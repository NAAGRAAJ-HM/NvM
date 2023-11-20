#define NVM_CRC_SOURCE

#include "Std_Types.hpp"

#include "NvM_Cfg.hpp"
#include "NvM_PrivateCfg.hpp"
#include "NvM_JobProc.hpp"
#include "NvM_Crc.hpp"

#ifndef static
#define static static
#endif

#define NVM_START_SEC_CODE
#include "MemMap.hpp"
static FUNC(void, NVM_PRIVATE_CODE) NvM_Crc_NoCrc_Calculate (NvM_ConstRamAddressType, uint16, NvM_CrcValuePtrType);
static FUNC(boolean, NVM_PRIVATE_CODE) NvM_Crc_NoCrc_Compare (NvM_CrcBufferConstPtrType, NvM_CrcValueRefType);
static FUNC(void, NVM_PRIVATE_CODE) NvM_Crc_NoCrc_CopyToBuffer (NvM_CrcBufferPtrType, NvM_CrcValueRefType);
static FUNC(void, NVM_PRIVATE_CODE) NvM_Crc_Crc16_Calculate (NvM_ConstRamAddressType, uint16, NvM_CrcValuePtrType);
static FUNC(boolean, NVM_PRIVATE_CODE) NvM_Crc_Crc16_Compare (NvM_CrcBufferConstPtrType, NvM_CrcValueRefType);
static FUNC(void, NVM_PRIVATE_CODE) NvM_Crc_Crc16_CopyToBuffer (NvM_CrcBufferPtrType, NvM_CrcValueRefType);
#define NVM_STOP_SEC_CODE
#include "MemMap.hpp"

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"
static CONST(struct NvM_CrcHandlerClass, NVM_PRIVATE_CONST) NvM_Crc_NoCrcHandler_t = {
      NvM_Crc_NoCrc_Calculate
   ,  NvM_Crc_NoCrc_Compare
   ,  NvM_Crc_NoCrc_CopyToBuffer
   ,  0
   ,  0
};

static CONST(struct NvM_CrcHandlerClass, NVM_PRIVATE_CONST) NvM_Crc_Crc16Handler_t = {
      NvM_Crc_Crc16_Calculate
   ,  NvM_Crc_Crc16_Compare
   ,  NvM_Crc_Crc16_CopyToBuffer
   ,  NVM_INITIAL_CRC_16_VALUE
   ,  2
};

#define NvM_Crc_Crc32Handler_t NvM_Crc_NoCrcHandler_t

static CONST(NvM_CrcHandlerClassConstPtr, NVM_PRIVATE_CONST) NvM_CrcHandlerTable_at[4] = {
      &NvM_Crc_NoCrcHandler_t
   ,  &NvM_Crc_NoCrcHandler_t
   ,  &NvM_Crc_Crc16Handler_t
   ,  &NvM_Crc_Crc32Handler_t
};
#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.hpp"

#define NVM_START_SEC_CODE
#include "MemMap.hpp"
FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_Create(NvM_CrcJobPtrType self, NvM_BlockIdType blockId, NvM_RamAddressType ramData_pt){
   const NvM_BlockDescrPtrType descr_pt = &(NvM_BlockDescriptorTable_at[NVM_BLOCK_FROM_DCM_ID(blockId)]);
   self->HandlerInstance_pt = NvM_CrcHandlerTable_at[descr_pt->CrcSettings];
   self->CurrentCrcValue = self->HandlerInstance_pt->initialCrcValue;
   self->RamData_pt = ramData_pt;
   self->CrcBuffer = (ramData_pt != NULL_PTR) ? (&ramData_pt[descr_pt->NvBlockLength_u16]) : NULL_PTR;
   self->RemainingLength_u16 = ((self->HandlerInstance_pt->crcLength > 0) && (ramData_pt != NULL_PTR)) ? descr_pt->NvBlockLength_u16 : 0u;
}

FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_Process(NvM_CrcJobPtrType self, uint16 processLength){
   if(self->RemainingLength_u16 > 0){
        const NvM_ConstRamAddressType currRamPtr = self->RamData_pt;
        uint16 currLength = self->RemainingLength_u16;
        if(currLength > processLength){
            currLength = processLength;
        }
        self->RemainingLength_u16 -= currLength;
        self->RamData_pt = &currRamPtr[currLength];
        self->HandlerInstance_pt->calc(currRamPtr, currLength, &self->CurrentCrcValue);
   }
}

FUNC(boolean, NVM_PRIVATE_CODE) NvM_CrcJob_Compare(NvM_CrcJobConstPtrType self){
   boolean result = FALSE;
   if(self->CrcBuffer != NULL_PTR){
        result = (self->HandlerInstance_pt->compare(self->CrcBuffer, (NvM_CrcValueRefType)&self->CurrentCrcValue));
   }
    return result;
}

FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_CopyToBuffer(NvM_CrcJobConstPtrType self){
   if(self->CrcBuffer != NULL_PTR){
        self->HandlerInstance_pt->copyToBuffer(self->CrcBuffer, (NvM_CrcValueRefType)&self->CurrentCrcValue);
   }
}

FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_ExportBufferedValue(NvM_CrcJobConstPtrType self, NvM_CrcBufferPtrType dest_pt){
   if((dest_pt != NULL_PTR) && (self->CrcBuffer != NULL_PTR)){
        self->HandlerInstance_pt->copyToBuffer(dest_pt, self->CrcBuffer);
   }
}

FUNC(void, NVM_PRIVATE_CODE) NvM_CrcJob_ImportBufferedValue(NvM_CrcJobConstPtrType self, NvM_CrcBufferConstPtrType src_pt){
   if((self->CrcBuffer != NULL_PTR) && (src_pt != NULL_PTR)){
        self->HandlerInstance_pt->copyToBuffer(self->CrcBuffer, src_pt);
   }
}

static FUNC(void, NVM_PRIVATE_CODE)  NvM_Crc_NoCrc_Calculate(NvM_ConstRamAddressType data_ptr, uint16 length, NvM_CrcValuePtrType currentValue){
    NVM_DUMMY_STATEMENT_CONST(data_ptr);
    NVM_DUMMY_STATEMENT(length);
    NVM_DUMMY_STATEMENT(currentValue);
}

static FUNC(boolean, NVM_PRIVATE_CODE) NvM_Crc_NoCrc_Compare(NvM_CrcBufferConstPtrType crcBuff, NvM_CrcValueRefType currentValue){
    NVM_DUMMY_STATEMENT_CONST(crcBuff);
    NVM_DUMMY_STATEMENT_CONST(currentValue);
    return TRUE;
}

static FUNC(void, NVM_PRIVATE_CODE) NvM_Crc_NoCrc_CopyToBuffer(NvM_CrcBufferPtrType dest, NvM_CrcValueRefType src){
    NVM_DUMMY_STATEMENT(dest);
    NVM_DUMMY_STATEMENT_CONST(src);
}

static FUNC(void, NVM_PRIVATE_CODE)  NvM_Crc_Crc16_Calculate(
      NvM_ConstRamAddressType data_pt
   ,  uint16                  length
   ,  NvM_CrcValuePtrType     currCrc
){
   typedef P2VAR(uint16, AUTOMATIC, NVM_CRC_BUFFER_PTR_CLASS) NvM_Crc16PtrType;
   *(NvM_Crc16PtrType)currCrc = LibAutosarCrc_u16Calculate(
         data_pt
      ,  length
      ,  *(NvM_Crc16PtrType)currCrc
      ,  FALSE
   );
}

static FUNC(boolean, NVM_PRIVATE_CODE) NvM_Crc_Crc16_Compare(NvM_CrcBufferConstPtrType crc1, NvM_CrcValueRefType crc2){
    return (boolean)((crc1[0] == crc2[0]) && (crc1[1] == crc2[1]));
}

static FUNC(void, NVM_PRIVATE_CODE) NvM_Crc_Crc16_CopyToBuffer (NvM_CrcBufferPtrType dest, NvM_CrcValueRefType src){
    dest[0] = src[0];
    dest[1] = src[1];
}
#define NVM_STOP_SEC_CODE
#include "MemMap.hpp"

