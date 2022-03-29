/******************************************************************************/
/* File   : NvM.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.hpp"
#include "infNvM_EcuM.hpp"
#include "infNvM_Dcm.hpp"
#include "infNvM_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define NVM_AR_RELEASE_MAJOR_VERSION                                           4
#define NVM_AR_RELEASE_MINOR_VERSION                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(NVM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible NVM_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(NVM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible NVM_AR_RELEASE_MINOR_VERSION!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_NvM:
      public abstract_module
{
   public:
      module_NvM(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, NVM_CODE) InitFunction   (void);
      FUNC(void, NVM_CODE) DeInitFunction (void);
      FUNC(void, NVM_CODE) MainFunction   (void);
};

extern VAR(module_NvM, NVM_VAR) NvM;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, NVM_VAR, NVM_CONST) gptrinfEcuMClient_NvM = &NvM;
CONSTP2VAR(infDcmClient,  NVM_VAR, NVM_CONST) gptrinfDcmClient_NvM  = &NvM;
CONSTP2VAR(infSchMClient, NVM_VAR, NVM_CONST) gptrinfSchMClient_NvM = &NvM;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgNvM.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_NvM, NVM_VAR) NvM(
   {
         0x0000
      ,  0xFFFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, NVM_CODE) module_NvM::InitFunction(void){
   NvM.IsInitDone = E_OK;
}

FUNC(void, NVM_CODE) module_NvM::DeInitFunction(void){
   NvM.IsInitDone = E_NOT_OK;
}

FUNC(void, NVM_CODE) module_NvM::MainFunction(void){
   //EcuM.CB_NotifyNvMJobEnd();
}

class class_NvM_Unused{
   public:
      FUNC(void, NVM_CODE) SetDataIndex             (void);
      FUNC(void, NVM_CODE) GetDataIndex             (void);
      FUNC(void, NVM_CODE) SetBlockProtection       (void);
      FUNC(void, NVM_CODE) GetErrorStatus           (void);
      FUNC(void, NVM_CODE) SetRamBlockStatus        (void);
      FUNC(void, NVM_CODE) SetBlockLockStatus       (void);
      FUNC(void, NVM_CODE) CancelJobs               (void);
      FUNC(void, NVM_CODE) ReadBlock                (void);
      FUNC(void, NVM_CODE) WriteBlock               (void);
      FUNC(void, NVM_CODE) RestoreBlockDefaults     (void);
      FUNC(void, NVM_CODE) EraseNvBlock             (void);
      FUNC(void, NVM_CODE) CancelWriteAll           (void);
      FUNC(void, NVM_CODE) InvalidateNvBlock        (void);
      FUNC(void, NVM_CODE) ReadPRAMBlock            (void);
      FUNC(void, NVM_CODE) WritePRAMBlock           (void);
      FUNC(void, NVM_CODE) RestorePRAMBlockDefaults (void);
      FUNC(void, NVM_CODE) ReadAll                  (void);
      FUNC(void, NVM_CODE) WriteAll                 (void);
      FUNC(void, NVM_CODE) ValidateAll              (void);
      FUNC(void, NVM_CODE) JobEndNotification       (void);
      FUNC(void, NVM_CODE) JobErrorNotification     (void);
};

FUNC(void, NVM_CODE) class_NvM_Unused::SetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::GetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::SetBlockProtection(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::GetErrorStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::SetRamBlockStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::SetBlockLockStatus(void){
}

#include "infMemIf_NvM.hpp"

FUNC(void, NVM_CODE) class_NvM_Unused::CancelJobs(void){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadBlock(void){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WriteBlock(void){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::RestoreBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::EraseNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::CancelWriteAll(void){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Unused::InvalidateNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadPRAMBlock(void){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WritePRAMBlock(void){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::RestorePRAMBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadAll(void){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WriteAll(void){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::ValidateAll(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::JobEndNotification(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::JobErrorNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

