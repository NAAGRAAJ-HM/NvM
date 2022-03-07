/*****************************************************/
/* File   : NvM.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "NvM_EcuM.h"
#include "NvM_SchM.h"
#include "NvM_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_NvM:
      public abstract_module
{
   public:
      FUNC(void, NVM_CODE) InitFunction   (void);
      FUNC(void, NVM_CODE) DeInitFunction (void);
      FUNC(void, NVM_CODE) MainFunction   (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_NvM     NvM;
infEcuMClient* gptrinfEcuMClient_NvM = &NvM;
infSchMClient* gptrinfSchMClient_NvM = &NvM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, NVM_CODE) module_NvM::InitFunction(void){
}

FUNC(void, NVM_CODE) module_NvM::DeInitFunction(void){
}

FUNC(void, NVM_CODE) module_NvM::MainFunction(void){
   //EcuM.CB_NotifyNvMJobEnd();
}

#include "MemIf_NvM.h"

FUNC(void, NVM_CODE) class_NvM_Unused::SetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::GetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::SetBlockProtection(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::GetErrorStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::GetVersionInfo(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::SetRamBlockStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::SetBlockLockStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::CancelJobs(void){
   NvM_Client_ptr_MemIf->Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadBlock(void){
   NvM_Client_ptr_MemIf->Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WriteBlock(void){
   NvM_Client_ptr_MemIf->Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::RestoreBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::EraseNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::CancelWriteAll(void){
   NvM_Client_ptr_MemIf->Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Unused::InvalidateNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadPRAMBlock(void){
   NvM_Client_ptr_MemIf->Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WritePRAMBlock(void){
   NvM_Client_ptr_MemIf->Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::RestorePRAMBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadAll(void){
   NvM_Client_ptr_MemIf->Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WriteAll(void){
   NvM_Client_ptr_MemIf->Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::ValidateAll(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::JobEndNotification(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::JobErrorNotification(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

