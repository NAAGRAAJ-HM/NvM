#pragma once
/******************************************************************************/
/* File   : NvM_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_NvM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define NVM_COREFUNCTIONALITIES                                                \
              FUNC(void, NVM_CODE) SetDataIndex             (void);            \
              FUNC(void, NVM_CODE) GetDataIndex             (void);            \
              FUNC(void, NVM_CODE) SetBlockProtection       (void);            \
              FUNC(void, NVM_CODE) GetErrorStatus           (void);            \
              FUNC(void, NVM_CODE) SetRamBlockStatus        (void);            \
              FUNC(void, NVM_CODE) SetBlockLockStatus       (void);            \
              FUNC(void, NVM_CODE) CancelJobs               (void);            \
              FUNC(void, NVM_CODE) ReadBlock                (void);            \
              FUNC(void, NVM_CODE) WriteBlock               (void);            \
              FUNC(void, NVM_CODE) RestoreBlockDefaults     (void);            \
              FUNC(void, NVM_CODE) EraseNvBlock             (void);            \
              FUNC(void, NVM_CODE) CancelWriteAll           (void);            \
              FUNC(void, NVM_CODE) InvalidateNvBlock        (void);            \
              FUNC(void, NVM_CODE) ReadPRAMBlock            (void);            \
              FUNC(void, NVM_CODE) WritePRAMBlock           (void);            \
              FUNC(void, NVM_CODE) RestorePRAMBlockDefaults (void);            \
              FUNC(void, NVM_CODE) ReadAll                  (void);            \
              FUNC(void, NVM_CODE) WriteAll                 (void);            \
              FUNC(void, NVM_CODE) ValidateAll              (void);            \
              FUNC(void, NVM_CODE) JobEndNotification       (void);            \
              FUNC(void, NVM_CODE) JobErrorNotification     (void);            \

#define NVM_COREFUNCTIONALITIES_VIRTUAL                                        \
      virtual FUNC(void, NVM_CODE) SetDataIndex             (void) = 0;        \
      virtual FUNC(void, NVM_CODE) GetDataIndex             (void) = 0;        \
      virtual FUNC(void, NVM_CODE) SetBlockProtection       (void) = 0;        \
      virtual FUNC(void, NVM_CODE) GetErrorStatus           (void) = 0;        \
      virtual FUNC(void, NVM_CODE) SetRamBlockStatus        (void) = 0;        \
      virtual FUNC(void, NVM_CODE) SetBlockLockStatus       (void) = 0;        \
      virtual FUNC(void, NVM_CODE) CancelJobs               (void) = 0;        \
      virtual FUNC(void, NVM_CODE) ReadBlock                (void) = 0;        \
      virtual FUNC(void, NVM_CODE) WriteBlock               (void) = 0;        \
      virtual FUNC(void, NVM_CODE) RestoreBlockDefaults     (void) = 0;        \
      virtual FUNC(void, NVM_CODE) EraseNvBlock             (void) = 0;        \
      virtual FUNC(void, NVM_CODE) CancelWriteAll           (void) = 0;        \
      virtual FUNC(void, NVM_CODE) InvalidateNvBlock        (void) = 0;        \
      virtual FUNC(void, NVM_CODE) ReadPRAMBlock            (void) = 0;        \
      virtual FUNC(void, NVM_CODE) WritePRAMBlock           (void) = 0;        \
      virtual FUNC(void, NVM_CODE) RestorePRAMBlockDefaults (void) = 0;        \
      virtual FUNC(void, NVM_CODE) ReadAll                  (void) = 0;        \
      virtual FUNC(void, NVM_CODE) WriteAll                 (void) = 0;        \
      virtual FUNC(void, NVM_CODE) ValidateAll              (void) = 0;        \
      virtual FUNC(void, NVM_CODE) JobEndNotification       (void) = 0;        \
      virtual FUNC(void, NVM_CODE) JobErrorNotification     (void) = 0;        \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_NvM_Functionality{
   public:
      NVM_COREFUNCTIONALITIES_VIRTUAL
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

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

