/*****************************************************/
/* File   : NvM.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "NvM.h"

#include "MemIf.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_NvM NvM;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, NVM_CODE) class_NvM::InitFunction(void){
}

FUNC(void, NVM_CODE) class_NvM::MainFunction(void){
   //EcuM.CB_NotifyNvMJobEnd();
}

FUNC(void, NVM_CODE) class_NvM::SetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM::GetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM::SetBlockProtection(void){
}

FUNC(void, NVM_CODE) class_NvM::GetErrorStatus(void){
}

FUNC(void, NVM_CODE) class_NvM::GetVersionInfo(void){
}

FUNC(void, NVM_CODE) class_NvM::SetRamBlockStatus(void){
}

FUNC(void, NVM_CODE) class_NvM::SetBlockLockStatus(void){
}

FUNC(void, NVM_CODE) class_NvM::CancelJobs(void){
   MemIf.Cancel();
}

FUNC(void, NVM_CODE) class_NvM::ReadBlock(void){
   MemIf.Read();
}

FUNC(void, NVM_CODE) class_NvM::WriteBlock(void){
   MemIf.Write();
}

FUNC(void, NVM_CODE) class_NvM::RestoreBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM::EraseNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM::CancelWriteAll(void){
   MemIf.Cancel();
}

FUNC(void, NVM_CODE) class_NvM::InvalidateNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM::ReadPRAMBlock(void){
   MemIf.Read();
}

FUNC(void, NVM_CODE) class_NvM::WritePRAMBlock(void){
   MemIf.Write();
}

FUNC(void, NVM_CODE) class_NvM::RestorePRAMBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM::ReadAll(void){
   MemIf.Read();
}

FUNC(void, NVM_CODE) class_NvM::WriteAll(void){
   MemIf.Write();
}

FUNC(void, NVM_CODE) class_NvM::ValidateAll(void){
}

FUNC(void, NVM_CODE) class_NvM::JobEndNotification(void){
}

FUNC(void, NVM_CODE) class_NvM::JobErrorNotification(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

