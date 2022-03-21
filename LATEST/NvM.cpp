/******************************************************************************/
/* File   : NvM.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "infNvM_Version.h"
#include "infNvM_EcuM.h"
#include "infNvM_Dcm.h"
#include "infNvM_SchM.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_NvM:
      public abstract_module
{
   public:
      FUNC(void, NVM_CODE) InitFunction   (void);
      FUNC(void, NVM_CODE) DeInitFunction (void);
      FUNC(void, NVM_CODE) GetVersionInfo (void);
      FUNC(void, NVM_CODE) MainFunction   (void);
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_NvM, NVM_VAR) NvM;
CONSTP2VAR(infEcuMClient, NVM_VAR, NVM_CONST) gptrinfEcuMClient_NvM = &NvM;
CONSTP2VAR(infDcmClient,  NVM_VAR, NVM_CONST) gptrinfDcmClient_NvM  = &NvM;
CONSTP2VAR(infSchMClient, NVM_VAR, NVM_CONST) gptrinfSchMClient_NvM = &NvM;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, NVM_CODE) module_NvM::InitFunction(void){
   NvM.IsInitDone = E_OK;
}

FUNC(void, NVM_CODE) module_NvM::DeInitFunction(void){
   NvM.IsInitDone = E_NOT_OK;
}

FUNC(void, NVM_CODE) module_NvM::GetVersionInfo(void){
}

FUNC(void, NVM_CODE) module_NvM::MainFunction(void){
   //EcuM.CB_NotifyNvMJobEnd();
}

#include "NvM_Unused.h"

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

#include "infMemIf_NvM.h"

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

