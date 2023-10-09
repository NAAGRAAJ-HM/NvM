#define NVM_SOURCE

#include "Std_Types.hpp"

#include "NvM.hpp"
#include "NvM_PrivateCfg.hpp"
#include "NvM_JobProc.hpp"
#include "NvM_Act.hpp"
#include "NvM_Qry.hpp"
#include "NvM_Queue.hpp"
#include "NvM_Crc.hpp"
#include "NvM_Cbk.hpp"

typedef P2CONST(NvM_RamMngmtAreaType, AUTOMATIC, NVM_CONFIG_DATA) NvM_RamMngmtConstPtrType;

#define NVM_START_SEC_VAR_FAST_8
#include "MemMap.hpp"
VAR(uint8, NVM_FAST_DATA) NvM_ApiFlags_u8;
#define NVM_STOP_SEC_VAR_FAST_8
#include "MemMap.hpp"


#define NVM_START_SEC_CODE
#include "MemMap.hpp"
static boolean NvM_WriteProtectionChecks(const NvM_RamMngmtConstPtrType mngmtPtr);
static boolean NvM_CheckBlockType(const NvM_BlockIdType BlockId);
static boolean NvM_CheckAddress(const NvM_BlockIdType BlockId, const void * RamPtr);
static boolean NvM_CheckBlockId(const NvM_BlockIdType BlockId);
static boolean NvM_CheckBlockPending(const NvM_BlockIdType blockId);
static NvM_RamMngmtPtrType NvM_GetMngmtAreaPtr(const NvM_BlockIdType blockId);

FUNC(void, NVM_PUBLIC_CODE) NvM_Init(void){
   uint16_least NvM_BlockCount_u16loc;
    NvM_QueueInit();
    NvM_ApiFlags_u8 = 0;
    NvM_BlockMngmtArea_at[0u].NvRamErrorStatus_u8 = NVM_REQ_OK;
    NvM_BlockCount_u16loc = NvM_NoOfBlockIds_t;
   do{
        --NvM_BlockCount_u16loc;
        NvM_BlockMngmtArea_at[NvM_BlockCount_u16loc].NvDataIndex_t = 0;
   }while(NvM_BlockCount_u16loc > 0);
    NvM_DcmBlockMngmt_t.NvDataIndex_t = 0;
    NvM_DcmBlockMngmt_t.NvRamAttributes_u8 = 0u;
    NvM_DcmBlockMngmt_t.NvRamErrorStatus_u8 = 0u;
    NvM_JobProcInit();
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetDataIndex(NvM_BlockIdType BlockId, uint8 DataIndex){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        if(NvM_CheckBlockType(BlockId) == TRUE){
            const NvM_RamMngmtPtrType NvM_RamMngt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
            NvM_RamMngt_ptloc->NvDataIndex_t = DataIndex;
            returnValue = E_OK;
        }
        else{
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetDataIndex(NvM_BlockIdType BlockId, P2VAR(uint8, AUTOMATIC, NVM_APPL_DATA) DataIndexPtr){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        if(NvM_CheckBlockType(BlockId) == TRUE){
            const NvM_RamMngmtPtrType NvM_RamMngt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
            *DataIndexPtr = NvM_RamMngt_ptloc->NvDataIndex_t;
            returnValue = E_OK;
        }
        else{
            *DataIndexPtr = 0;
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetBlockProtection(NvM_BlockIdType BlockId, boolean ProtectionEnabled){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
        if((NvM_BlockDescriptorTable_at[NVM_BLOCK_FROM_DCM_ID(BlockId)].Flags_u8 & NVM_BLOCK_WRITE_BLOCK_ONCE_ON) == 0){
            NvM_EnterCriticalSection();
            if(ProtectionEnabled){
                NvM_RamMngmt_ptloc->NvRamAttributes_u8 |= NVM_WR_PROT_SET;
            }
            else{
                NvM_RamMngmt_ptloc->NvRamAttributes_u8 &= NVM_WR_PROT_CL;
            }
            NvM_ExitCriticalSection();
            returnValue = E_OK;
        }
        else{
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_GetErrorStatus(NvM_BlockIdType BlockId
   ,  P2VAR(NvM_RequestResultType, AUTOMATIC, NVM_APPL_DATA) RequestResultPtr
){
   Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        if(NvM_CheckBlockPending(BlockId) == TRUE){
            *RequestResultPtr = NVM_REQ_PENDING;
        }
        else{
            const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
            *RequestResultPtr = NvM_RamMngmt_ptloc->NvRamErrorStatus_u8;
        }
        returnValue = E_OK;
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(void, NVM_PUBLIC_CODE) NvM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, NVM_APPL_DATA) Versioninfo){
   uint8 detErrorId = NVM_E_NO_ERROR;
        Versioninfo->vendorID         = NVM_VENDOR_ID;
        Versioninfo->moduleID         = NVM_MODULE_ID;
        Versioninfo->sw_major_version = NVM_SW_MAJOR_VERSION;
        Versioninfo->sw_minor_version = NVM_SW_MINOR_VERSION;
        Versioninfo->sw_patch_version = NVM_SW_PATCH_VERSION;
    NVM_DUMMY_STATEMENT(detErrorId);
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType BlockId, boolean BlockChanged){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        if(NvM_CheckAddress(BlockId, NULL_PTR) == TRUE){
            const NvM_RamMngmtPtrType blockMngmtPtr = NvM_GetMngmtAreaPtr(BlockId);
            NvM_EnterCriticalSection();
            if(BlockChanged){
                blockMngmtPtr->NvRamAttributes_u8 |= (NVM_STATE_CHANGED_SET | NVM_STATE_VALID_SET);
                blockMngmtPtr->NvRamAttributes_u8 &= NVM_NVRAM_UPTODATE_CL;
                NvM_ExitCriticalSection();
            }
            else{
                blockMngmtPtr->NvRamAttributes_u8 &= (NVM_STATE_CHANGED_CL & NVM_STATE_VALID_CL);
                NvM_ExitCriticalSection();
            }
            returnValue = E_OK;
        }
        else{
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_ReadBlock(NvM_BlockIdType BlockId, P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        if(NvM_QueueJob(BlockId, NVM_INT_FID_READ_BLOCK, (NvM_RamAddressType)NvM_DstPtr)){
            if(NvM_DstPtr == NULL_PTR){
                const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
                NvM_EnterCriticalSection();
                NvM_RamMngmt_ptloc->NvRamAttributes_u8 &= (NVM_STATE_VALID_CL & NVM_STATE_CHANGED_CL);
                NvM_ExitCriticalSection();
            }
            returnValue = E_OK;
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_WriteBlock(NvM_BlockIdType BlockId, P2CONST(void, AUTOMATIC, NVM_APPL_DATA) NvM_SrcPtr){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
        if(NvM_WriteProtectionChecks(NvM_RamMngmt_ptloc) == TRUE){
            if(NvM_QueueJob(BlockId, NVM_INT_FID_WRITE_BLOCK, (NvM_RamAddressType)NvM_SrcPtr)){
                if(NvM_SrcPtr == NULL_PTR){
                    NvM_EnterCriticalSection();
                    NvM_RamMngmt_ptloc->NvRamAttributes_u8 |= (NVM_STATE_VALID_SET | NVM_STATE_CHANGED_SET);
                    NvM_ExitCriticalSection();
                }
                returnValue = E_OK;
            }
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_RestoreBlockDefaults(NvM_BlockIdType BlockId, P2VAR(void, AUTOMATIC, NVM_APPL_DATA) NvM_DstPtr){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        if(NvM_QueueJob(BlockId, NVM_INT_FID_RESTORE_DEFAULTS, (NvM_RamAddressType)NvM_DstPtr)){
            if(NvM_DstPtr == NULL_PTR){
                const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
                NvM_EnterCriticalSection();
                NvM_RamMngmt_ptloc->NvRamAttributes_u8 &= (NVM_STATE_VALID_CL & NVM_STATE_CHANGED_CL);
                NvM_ExitCriticalSection();
            }
            returnValue = E_OK;
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_EraseNvBlock(NvM_BlockIdType BlockId){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
        if(NvM_WriteProtectionChecks(NvM_RamMngmt_ptloc) == TRUE){
            returnValue = NvM_QueueJob(BlockId, NVM_INT_FID_ERASE_BLOCK, NULL_PTR) ? E_OK : E_NOT_OK;
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_InvalidateNvBlock(NvM_BlockIdType BlockId){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        const NvM_RamMngmtPtrType NvM_RamMngmt_ptloc = NvM_GetMngmtAreaPtr(BlockId);
        if(NvM_WriteProtectionChecks(NvM_RamMngmt_ptloc) == TRUE){
            returnValue = NvM_QueueJob(BlockId, NVM_INT_FID_INVALIDATE_NV_BLOCK, NULL_PTR) ? E_OK : E_NOT_OK;
        }
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(Std_ReturnType, NVM_PUBLIC_CODE) NvM_CancelJobs(NvM_BlockIdType BlockId){
    Std_ReturnType returnValue = E_NOT_OK;
   uint8 detErrorId = NVM_E_NO_ERROR;
        returnValue = (NvM_UnQueueJob(BlockId) == TRUE) ? E_OK : E_NOT_OK;
    NVM_DUMMY_STATEMENT(detErrorId);
    return returnValue;
}

FUNC(void, NVM_PUBLIC_CODE) NvM_ReadAll(void){
   uint8 detErrorId = NVM_E_NO_ERROR;
        NvM_EnterCriticalSection();
        NvM_BlockMngmtArea_at[0].NvRamErrorStatus_u8 = NVM_REQ_PENDING;
        NvM_ApiFlags_u8 |= NVM_APIFLAG_READ_ALL_SET;
        NvM_ExitCriticalSection();
        NvM_MultiBlockCbk(NVM_READ_ALL, NVM_REQ_PENDING);
    NVM_DUMMY_STATEMENT(detErrorId);
}

FUNC(void, NVM_PUBLIC_CODE) NvM_WriteAll(void){
   uint8 detErrorId = NVM_E_NO_ERROR;
        NvM_EnterCriticalSection();
        NvM_BlockMngmtArea_at[0u].NvRamErrorStatus_u8 = NVM_REQ_PENDING;
        NvM_ApiFlags_u8 &= (NVM_APIFLAG_KILL_WR_ALL_CL & NVM_APIFLAG_CANCEL_WR_ALL_CL);
        NvM_ApiFlags_u8 |= NVM_APIFLAG_WRITE_ALL_SET;
        NvM_ExitCriticalSection();
        NvM_MultiBlockCbk(NVM_WRITE_ALL, NVM_REQ_PENDING);
    NVM_DUMMY_STATEMENT(detErrorId);
}

FUNC(void, NVM_PUBLIC_CODE) NvM_CancelWriteAll(void){
   uint8 detErrorId = NVM_E_NO_ERROR;
        NvM_EnterCriticalSection();
        NvM_ApiFlags_u8 |= NVM_APIFLAG_CANCEL_WR_ALL_SET;
        NvM_ExitCriticalSection();
    NVM_DUMMY_STATEMENT(detErrorId);
}

FUNC(void, NVM_PUBLIC_CODE) NvM_KillWriteAll(void){
   uint8 detErrorId = NVM_E_NO_ERROR;
        NvM_BlockIdType blockEndNotificationId = 0;
        boolean writeAllEndNotification = FALSE;
        NvM_EnterCriticalSection();
        if((NvM_ApiFlags_u8 & NVM_APIFLAG_WRITE_ALL_SET) != 0){
            NvM_ApiFlags_u8 &= NVM_APIFLAG_WRITE_ALL_CL;
            NvM_ApiFlags_u8 |= NVM_APIFLAG_KILL_WR_ALL_SET | NVM_APIFLAG_CANCEL_WR_ALL_SET;
            if((NvM_CurrentJob_t.JobServiceId_t == NVM_INT_FID_WRITE_ALL) && (NvM_CheckBlockId(NvM_CurrentJob_t.JobBlockId_t))){
                const NvM_RamMngmtPtrType mngmt_pt = NvM_CurrentBlockInfo_t.Mngmt_pt;
                blockEndNotificationId = NvM_CurrentJob_t.JobBlockId_t;
                mngmt_pt->NvRamErrorStatus_u8 =
                    ((mngmt_pt->NvRamAttributes_u8 & NVM_STATE_VALID_SET) != 0) ? NVM_REQ_OK : NVM_REQ_BLOCK_SKIPPED;
            }
            NvM_BlockMngmtArea_at[0].NvRamErrorStatus_u8 = NVM_REQ_CANCELED;
            writeAllEndNotification = TRUE;
        }
        NvM_ExitCriticalSection();
        if(blockEndNotificationId > 0){
            NvM_BlockNotification(blockEndNotificationId, NVM_WRITE_ALL, NVM_REQ_CANCELED);
        }
        if(writeAllEndNotification == TRUE){
            NvM_MultiBlockCbk(NVM_WRITE_ALL, NVM_REQ_CANCELED);
        }
    NVM_DUMMY_STATEMENT(detErrorId);
}

FUNC(void, NVM_PUBLIC_CODE) NvM_MainFunction(void){
   uint8 detErrorId = NVM_E_NO_ERROR;
        NvM_CurrentBlockInfo_t.InternalFlags_u8 &= NVM_INTFLAG_WAIT_CL;
   do{
            NvM_TaskState_t = NvM_Fsm(NvM_TaskState_t);
            NvM_JobMainState_t = NvM_Fsm(NvM_JobMainState_t);
            NvM_JobSubState_t = NvM_Fsm(NvM_JobSubState_t);
        }
        while((NvM_CurrentBlockInfo_t.InternalFlags_u8 & NVM_INTFLAG_WAIT_SET) == 0);
    NVM_DUMMY_STATEMENT(detErrorId);
}

FUNC(void, NVM_PUBLIC_CODE) NvM_JobEndNotification(void){
     NvM_CurrentBlockInfo_t.LastResult_t = NVM_REQ_OK;
}

FUNC(void, NVM_PUBLIC_CODE) NvM_JobErrorNotification(void){
   switch(MemIf_GetJobResult((uint8)NvM_CurrentBlockInfo_t.Descriptor_pt->DeviceId_u8)){
      case MEMIF_BLOCK_INCONSISTENT: NvM_CurrentBlockInfo_t.LastResult_t = NVM_REQ_INTEGRITY_FAILED; break;
      case MEMIF_BLOCK_INVALID:      NvM_CurrentBlockInfo_t.LastResult_t = NVM_REQ_NV_INVALIDATED;   break;
      default:                       NvM_CurrentBlockInfo_t.LastResult_t = NVM_REQ_NOT_OK;
   }
}

FUNC(void, NVM_PUBLIC_CODE) NvM_SetBlockLockStatus(NvM_BlockIdType BlockId, boolean BlockLocked){
   uint8 detErrorId = NVM_E_NO_ERROR;
        NvM_EnterCriticalSection();
        if(BlockLocked){
            NvM_BlockMngmtArea_at[NVM_BLOCK_FROM_DCM_ID(BlockId)].NvRamAttributes_u8 |= NVM_LOCK_STAT_SET;
        }
        else{
            NvM_BlockMngmtArea_at[NVM_BLOCK_FROM_DCM_ID(BlockId)].NvRamAttributes_u8 &= NVM_LOCK_STAT_CL;
        }
        NvM_ExitCriticalSection();
    NVM_DUMMY_STATEMENT(detErrorId);
}

static boolean NvM_WriteProtectionChecks(const NvM_RamMngmtConstPtrType mngmtPtr){
   boolean returnValue = FALSE;
   if((mngmtPtr->NvRamAttributes_u8 & NVM_WR_PROT_SET) != 0){
    	NvM_DemReportErrorWriteProtected();
   }
   else if(mngmtPtr != &NvM_DcmBlockMngmt_t){
        returnValue = (boolean)((mngmtPtr->NvRamAttributes_u8 & NVM_LOCK_STAT_SET) == 0);
   }
   else{
        returnValue = TRUE;
   }
    return returnValue;
}

static boolean NvM_CheckBlockType(const NvM_BlockIdType BlockId){
    return (boolean)((NvM_BlockDescriptorTable_at[NVM_BLOCK_FROM_DCM_ID(BlockId)].MngmtType_t & NVM_BLOCK_DATASET) != 0);
}

static boolean NvM_CheckAddress(const NvM_BlockIdType BlockId, const void * RamPtr){
    NvM_BlockDescrPtrType descPtr = &NvM_BlockDescriptorTable_at[NVM_BLOCK_FROM_DCM_ID(BlockId)];
   boolean returnValue = TRUE;
   if(RamPtr == NULL_PTR){
        returnValue = (boolean)((NVM_BLOCK_FROM_DCM_ID(BlockId) == BlockId) &&
            ((descPtr->RamBlockDataAddr_t != NULL_PTR) || (descPtr->CbkGetMirrorFunc_pt != NULL_PTR)));
   }
    return returnValue;
}

static boolean NvM_CheckBlockId(const NvM_BlockIdType BlockId){
    return (boolean)((NVM_BLOCK_FROM_DCM_ID(BlockId) > 0) && (NVM_BLOCK_FROM_DCM_ID(BlockId) < NvM_NoOfBlockIds_t));
}

static boolean NvM_CheckBlockPending(const NvM_BlockIdType blockId){
   boolean blockPending = FALSE;
   if((blockId > 0x0) && ((NvM_CurrentJob_t.JobServiceId_t == NVM_INT_FID_WRITE_ALL) || (NvM_CurrentJob_t.JobServiceId_t == NVM_INT_FID_READ_ALL))){
        if((NvM_ApiFlags_u8 & NVM_APIFLAG_WRITE_ALL_SET) == NVM_APIFLAG_WRITE_ALL_SET){
            blockPending = (boolean)(blockId < NvM_CurrentJob_t.JobBlockId_t);
        }
        else{
            blockPending = (boolean)(blockId > NvM_CurrentJob_t.JobBlockId_t);
        }
   }
   else{
        blockPending = (boolean)(NvM_GetMngmtAreaPtr(blockId)->NvRamErrorStatus_u8 == NVM_REQ_PENDING);
   }
    return blockPending;
}

static NvM_RamMngmtPtrType NvM_GetMngmtAreaPtr(const NvM_BlockIdType blockId){
    return (blockId == NVM_BLOCK_FROM_DCM_ID(blockId)) ? (&NvM_BlockMngmtArea_at[blockId]) : (&NvM_DcmBlockMngmt_t);
}

#define NVM_STOP_SEC_CODE
#include "MemMap.hpp"

