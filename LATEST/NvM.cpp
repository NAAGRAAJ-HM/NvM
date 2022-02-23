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
   ,  public interface_NvM_EcuM
   ,  public interface_NvM_SchM
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
module_NvM NvM;

interface_NvM_EcuM *EcuM_Client_ptr_NvM = &NvM;
interface_NvM_SchM *SchM_Client_ptr_NvM = &NvM;

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
   MemIf.Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadBlock(void){
   MemIf.Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WriteBlock(void){
   MemIf.Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::RestoreBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::EraseNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::CancelWriteAll(void){
   MemIf.Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Unused::InvalidateNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadPRAMBlock(void){
   MemIf.Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WritePRAMBlock(void){
   MemIf.Write();
}

FUNC(void, NVM_CODE) class_NvM_Unused::RestorePRAMBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Unused::ReadAll(void){
   MemIf.Read();
}

FUNC(void, NVM_CODE) class_NvM_Unused::WriteAll(void){
   MemIf.Write();
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

