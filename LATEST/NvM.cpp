/******************************************************************************/
/* File   : NvM.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "NvM_core.hpp"
#include "infNvM_EcuM.hpp"
#include "infNvM_Dcm.hpp"
#include "infNvM_SchM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define NVM_AR_RELEASE_VERSION_MAJOR                                           4
#define NVM_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(NVM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible NVM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(NVM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible NVM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_NvM:
      public abstract_module
   ,  public class_NvM_Functionality
{
   public:
      module_NvM(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, NVM_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, NVM_CONFIG_DATA, NVM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, NVM_CODE) DeInitFunction (void);
      FUNC(void, NVM_CODE) MainFunction   (void);
};

extern VAR(module_NvM, NVM_VAR) NvM;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, NVM_VAR, NVM_CONST) gptrinfEcuMClient_NvM = &NvM;
CONSTP2VAR(infDcmClient,  NVM_VAR, NVM_CONST) gptrinfDcmClient_NvM  = &NvM;
CONSTP2VAR(infSchMClient, NVM_VAR, NVM_CONST) gptrinfSchMClient_NvM = &NvM;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgNvM.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_NvM, NVM_VAR) NvM(
   {
         NVM_AR_RELEASE_VERSION_MAJOR
      ,  NVM_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, NVM_CODE) module_NvM::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, NVM_CONFIG_DATA, NVM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == NvM_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == NvM_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgNvM;
         }
      }
      IsInitDone = E_OK;
#if(STD_ON == NvM_InitCheck)
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::DeInitFunction(void){
#if(STD_ON == NvM_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == NvM_InitCheck)
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::MainFunction(void){
#if(STD_ON == NvM_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      //EcuM.CB_NotifyNvMJobEnd();
#if(STD_ON == NvM_InitCheck)
   }
#endif
}

FUNC(void, NVM_CODE) class_NvM_Functionality::SetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::GetDataIndex(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::SetBlockProtection(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::GetErrorStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::SetRamBlockStatus(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::SetBlockLockStatus(void){
}

#include "infMemIf_NvM.hpp"

FUNC(void, NVM_CODE) class_NvM_Functionality::CancelJobs(void){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::ReadBlock(void){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::WriteBlock(void){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::RestoreBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::EraseNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::CancelWriteAll(void){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::InvalidateNvBlock(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::ReadPRAMBlock(void){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::WritePRAMBlock(void){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::RestorePRAMBlockDefaults(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::ReadAll(void){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::WriteAll(void){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) class_NvM_Functionality::ValidateAll(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::JobEndNotification(void){
}

FUNC(void, NVM_CODE) class_NvM_Functionality::JobErrorNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

