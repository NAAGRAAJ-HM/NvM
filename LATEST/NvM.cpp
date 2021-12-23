#include "NvM.h"

#include "MemIf.h"

class_NvM NvM;

void class_NvM::InitFunction(void){
}

void class_NvM::MainFunction(void){
   //EcuM.CB_NotifyNvMJobEnd();
}

void class_NvM::SetDataIndex(void){
}

void class_NvM::GetDataIndex(void){
}

void class_NvM::SetBlockProtection(void){
}

void class_NvM::GetErrorStatus(void){
}

void class_NvM::GetVersionInfo(void){
}

void class_NvM::SetRamBlockStatus(void){
}

void class_NvM::SetBlockLockStatus(void){
}

void class_NvM::CancelJobs(void){
   MemIf.Cancel();
}

void class_NvM::ReadBlock(void){
   MemIf.Read();
}

void class_NvM::WriteBlock(void){
   MemIf.Write();
}

void class_NvM::RestoreBlockDefaults(void){
}

void class_NvM::EraseNvBlock(void){
}

void class_NvM::CancelWriteAll(void){
   MemIf.Cancel();
}

void class_NvM::InvalidateNvBlock(void){
}

void class_NvM::ReadPRAMBlock(void){
   MemIf.Read();
}

void class_NvM::WritePRAMBlock(void){
   MemIf.Write();
}

void class_NvM::RestorePRAMBlockDefaults(void){
}

void class_NvM::ReadAll(void){
   MemIf.Read();
}

void class_NvM::WriteAll(void){
   MemIf.Write();
}

void class_NvM::ValidateAll(void){
}

void class_NvM::JobEndNotification(void){
}

void class_NvM::JobErrorNotification(void){
}

