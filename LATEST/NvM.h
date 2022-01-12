#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_NvM.h"

class class_NvM{
   public:
      FUNC(void, NVM_CODE) InitFunction             (void);
      FUNC(void, NVM_CODE) MainFunction             (void);
      FUNC(void, NVM_CODE) SetDataIndex             (void);
      FUNC(void, NVM_CODE) GetDataIndex             (void);
      FUNC(void, NVM_CODE) SetBlockProtection       (void);
      FUNC(void, NVM_CODE) GetErrorStatus           (void);
      FUNC(void, NVM_CODE) GetVersionInfo           (void);
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

extern class_NvM NvM;


