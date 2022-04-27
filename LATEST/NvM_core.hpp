#pragma once
/******************************************************************************/
/* File   : NvM_core.hpp                                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_NvM_Functionality{
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

