#pragma once

#include "Std_Types.h"

class class_NvM{
   public:
      void InitFunction             (void);
      void MainFunction             (void);
      void SetDataIndex             (void);
      void GetDataIndex             (void);
      void SetBlockProtection       (void);
      void GetErrorStatus           (void);
      void GetVersionInfo           (void);
      void SetRamBlockStatus        (void);
      void SetBlockLockStatus       (void);
      void CancelJobs               (void);
      void ReadBlock                (void);
      void WriteBlock               (void);
      void RestoreBlockDefaults     (void);
      void EraseNvBlock             (void);
      void CancelWriteAll           (void);
      void InvalidateNvBlock        (void);
      void ReadPRAMBlock            (void);
      void WritePRAMBlock           (void);
      void RestorePRAMBlockDefaults (void);
      void ReadAll                  (void);
      void WriteAll                 (void);
      void ValidateAll              (void);
      void JobEndNotification       (void);
      void JobErrorNotification     (void);
};

extern class_NvM NvM;


