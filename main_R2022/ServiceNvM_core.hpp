#pragma once
/******************************************************************************/
/* File   : ServiceNvM_core.hpp                                                      */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_ServiceNvM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICENVM_CORE_FUNCTIONALITIES                                               \
              FUNC(void, SERVICENVM_CODE) SetDataIndex             (void);            \
              FUNC(void, SERVICENVM_CODE) GetDataIndex             (void);            \
              FUNC(void, SERVICENVM_CODE) SetBlockProtection       (void);            \
              FUNC(void, SERVICENVM_CODE) GetErrorStatus           (void);            \
              FUNC(void, SERVICENVM_CODE) SetRamBlockStatus        (void);            \
              FUNC(void, SERVICENVM_CODE) SetBlockLockStatus       (void);            \
              FUNC(void, SERVICENVM_CODE) McalCancelJobs               (void);            \
              FUNC(void, SERVICENVM_CODE) ReadBlock                (void);            \
              FUNC(void, SERVICENVM_CODE) WriteBlock               (void);            \
              FUNC(void, SERVICENVM_CODE) RestoreBlockDefaults     (void);            \
              FUNC(void, SERVICENVM_CODE) EraseNvBlock             (void);            \
              FUNC(void, SERVICENVM_CODE) McalCancelWriteAll           (void);            \
              FUNC(void, SERVICENVM_CODE) InvalidateNvBlock        (void);            \
              FUNC(void, SERVICENVM_CODE) ReadPRAMBlock            (void);            \
              FUNC(void, SERVICENVM_CODE) WritePRAMBlock           (void);            \
              FUNC(void, SERVICENVM_CODE) RestorePRAMBlockDefaults (void);            \
              FUNC(void, SERVICENVM_CODE) ReadAll                  (void);            \
              FUNC(void, SERVICENVM_CODE) WriteAll                 (void);            \
              FUNC(void, SERVICENVM_CODE) ValidateAll              (void);            \
              FUNC(void, SERVICENVM_CODE) JobEndNotification       (void);            \
              FUNC(void, SERVICENVM_CODE) JobErrorNotification     (void);            \

#define SERVICENVM_CORE_FUNCTIONALITIES_VIRTUAL                                       \
      virtual FUNC(void, SERVICENVM_CODE) SetDataIndex             (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) GetDataIndex             (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) SetBlockProtection       (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) GetErrorStatus           (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) SetRamBlockStatus        (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) SetBlockLockStatus       (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) McalCancelJobs               (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) ReadBlock                (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) WriteBlock               (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) RestoreBlockDefaults     (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) EraseNvBlock             (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) McalCancelWriteAll           (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) InvalidateNvBlock        (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) ReadPRAMBlock            (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) WritePRAMBlock           (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) RestorePRAMBlockDefaults (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) ReadAll                  (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) WriteAll                 (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) ValidateAll              (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) JobEndNotification       (void) = 0;        \
      virtual FUNC(void, SERVICENVM_CODE) JobErrorNotification     (void) = 0;        \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceNvM_Functionality{
   public:
      SERVICENVM_CORE_FUNCTIONALITIES_VIRTUAL
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

