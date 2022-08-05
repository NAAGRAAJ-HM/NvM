/******************************************************************************/
/* File   : ServiceNvM.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceNvM.hpp"
#include "infServiceNvM_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICENVM_AR_RELEASE_VERSION_MAJOR                                           4
#define SERVICENVM_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SERVICENVM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SERVICENVM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SERVICENVM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SERVICENVM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_ServiceNvM, SERVICENVM_VAR) ServiceNvM;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#include <cstring>
#include "Const.hpp"
#include "Cfg.hpp"

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICENVM_CONST,       SERVICENVM_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICENVM_CONFIG_DATA, SERVICENVM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceNvM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstServiceNvM_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceNvM_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }

      if(FALSE){
         memcpy(
               (      void*)&CfgGen_ServiceNvM
            ,  (const void*)&CfgGen_McalFls
            ,  sizeof(CfgGen_Type)
         );
      }
      else{
         memcpy(
               (      void*)&CfgGen_ServiceNvM
            ,  (const void*)&PBcfgGen_ROM
            ,  sizeof(CfgGen_Type)
         );
      }

#if(STD_ON == _ReSIM)
/*
      cout<<endl<<endl<<"CfgMcalAdc";
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalAdc.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalAdc.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceBswM";
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceBswM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceBswM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalCan";
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalCan.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCan.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabCanIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabCanIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceCanNm";
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgServiceCanNm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceCanSm";
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgServiceCanSm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCanSm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabCanTp";
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabCanTp.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCanTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceCom";
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceCom.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCom.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceComM";
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceComM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceComM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalCry";
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalCry.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalCry.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabCryIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabCryIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabCryIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceCsm";
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceCsm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceCsm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceDcm";
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceDcm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDcm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceDem";
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceDem.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDem.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceDet";
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceDet.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDet.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalDio";
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalDio.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalDio.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceDlt";
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceDlt.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceDlt.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabEa";
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.bDevErrorDetect                          = %d", CfgGen_ServiceNvM.CfgEcuabEa.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8ArVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8ArVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8IDVendor                   = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8IDModule                   = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8IDInstance                 = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8SwVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8SwVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8SwVersionPatch             = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEa.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceEcuM";
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceEcuM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceEcuM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalEep";
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalEep.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEep.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalEth";
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalEth.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalEth.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabEthIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabEthIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabEthIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabFee";
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgEcuabFee.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFee.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceFiM";
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceFiM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFiM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalFls";
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalFls.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFls.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalFr";
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.bDevErrorDetect                          = %d", CfgGen_ServiceNvM.CfgMcalFr.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8ArVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8ArVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8IDVendor                   = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8IDModule                   = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8IDInstance                 = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8SwVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8SwVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8SwVersionPatch             = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalFr.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabFrIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgEcuabFrIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceFrNm";
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceFrNm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceFrNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabFrTp";
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgEcuabFrTp.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabFrTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalGpt";
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalGpt.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalGpt.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalIcu";
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalIcu.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalIcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceIpduM";
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgServiceIpduM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceIpduM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabJ1939Tp";
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.bDevErrorDetect                     = %d", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8ArVersionMajor        = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8ArVersionMinor        = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8IDVendor              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8IDModule              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8IDInstance            = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8SwVersionMajor        = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8SwVersionMinor        = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8SwVersionPatch        = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabJ1939Tp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalLin";
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalLin.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalLin.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabLinIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabLinIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabLinTp";
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabLinTp.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabLinTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalMcu";
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalMcu.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalMcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabMemIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabMemIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabMemIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceNm";
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.bDevErrorDetect                          = %d", CfgGen_ServiceNvM.CfgServiceNm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8ArVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8ArVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8IDVendor                   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8IDModule                   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8IDInstance                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8SwVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8SwVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8SwVersionPatch             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceNvM";
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgServiceNvM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceNvM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalOcu";
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalOcu.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalOcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceOs";
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.bDevErrorDetect                          = %d", CfgGen_ServiceNvM.CfgServiceOs.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8ArVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8ArVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8IDVendor                   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8IDModule                   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8IDInstance                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8SwVersionMajor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8SwVersionMinor             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8SwVersionPatch             = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceOs.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalPort";
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgMcalPort.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPort.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalPwm";
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalPwm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalPwm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgProjectARA";
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgProjectARA.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgProjectARA.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceSchM";
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceSchM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSchM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceSecOC";
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgServiceSecOC.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSecOC.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceSokFm";
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgServiceSokFm.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSokFm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalSpi";
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalSpi.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalSpi.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceStartUp";
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.bDevErrorDetect                     = %d", CfgGen_ServiceNvM.CfgServiceStartUp.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8ArVersionMajor        = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8ArVersionMinor        = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8IDVendor              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8IDModule              = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8IDInstance            = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8SwVersionMajor        = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8SwVersionMinor        = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8SwVersionPatch        = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStartUp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceStbM";
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceStbM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceStbM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgApplSwcFoc";
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.bDevErrorDetect                  = %d", CfgGen_ServiceNvM.CfgApplSwcFoc.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8ArVersionMajor     = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8ArVersionMinor     = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8IDVendor           = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8IDModule           = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8IDInstance         = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8SwVersionMajor     = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8SwVersionMinor     = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8SwVersionPatch     = 0x%2.2X", CfgGen_ServiceNvM.CfgApplSwcFoc.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceSwcEcuM";
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.bDevErrorDetect              = %d", CfgGen_ServiceNvM.CfgServiceSwcEcuM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcEcuM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceSwcOs";
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.bDevErrorDetect                = %d", CfgGen_ServiceNvM.CfgServiceSwcOs.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8ArVersionMajor   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8ArVersionMinor   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8IDVendor         = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8IDModule         = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8IDInstance       = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8SwVersionMajor   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8SwVersionMinor   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8SwVersionPatch   = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceSwcOs.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceVkms";
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceVkms.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceVkms.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcalWdg";
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.bDevErrorDetect                         = %d", CfgGen_ServiceNvM.CfgMcalWdg.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8ArVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8ArVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8IDVendor                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8IDModule                  = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8IDInstance                = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8SwVersionMajor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8SwVersionMinor            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8SwVersionPatch            = 0x%2.2X", CfgGen_ServiceNvM.CfgMcalWdg.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuabWdgIf";
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.bDevErrorDetect                       = %d", CfgGen_ServiceNvM.CfgEcuabWdgIf.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8IDVendor                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8IDModule                = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8IDInstance              = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", CfgGen_ServiceNvM.CfgEcuabWdgIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgServiceWdgM";
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServiceWdgM.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServiceWdgM.VersionInfo.u8SwVersionPatch);
*/
/*
      cout<<endl<<endl<<"CfgServicePduR";
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.bDevErrorDetect                        = %d", CfgGen_ServiceNvM.CfgServicePduR.bDevErrorDetect);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8ArVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8ArVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8IDVendor                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8IDVendor);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8IDModule                 = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8IDModule);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8IDInstance               = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8IDInstance);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8SwVersionMajor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8SwVersionMinor           = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8SwVersionPatch           = 0x%2.2X", CfgGen_ServiceNvM.CfgServicePduR.VersionInfo.u8SwVersionPatch);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.Id                                = 0x%4.4X", CfgGen_ServiceNvM.CfgServicePduR.Core.Id);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bUpperModule            = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bUpperModule);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bLowerModule            = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bLowerModule);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCommunicationInterface = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCommunicationInterface);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTransportProtocol      = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTransportProtocol);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTransmit               = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTransmit);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTransmitTp             = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTransmitTp);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTxConfirmation         = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTxConfirmation);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTxConfirmationTp       = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTxConfirmationTp);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bRxIndication           = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bRxIndication);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bRxIndicationTp         = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bRxIndicationTp);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCancelTransmit         = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCancelTransmit);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCancelReceive          = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCancelReceive);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCopyTxData             = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCopyTxData);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCopyRxData             = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bCopyRxData);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTriggerTransmit        = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bTriggerTransmit);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bReTransmition          = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bReTransmition);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bStartOfReception       = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bStartOfReception);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bUseTag                 = %d", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrClients[0]->bUseTag);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.u16CntMaxRoutingPathGroup         = 0x%4.4X", CfgGen_ServiceNvM.CfgServicePduR.Core.u16CntMaxRoutingPathGroup);
      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups                        = 0x%p", (void*)CfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups);
*/
//      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->Id                   = 0x%4.4X", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->Id);
//      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->u16CntMaxRoutingPath = 0x%4.4X", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->u16CntMaxRoutingPath);
//      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->astGroup[0].ptrSrc   = 0x%p", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->astGroup[0].ptrSrc);
//      printf("\nCfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->astGroup[0].ptrDst   = 0x%p", CfgGen_ServiceNvM.CfgServicePduR.Core.aptrGroups[0]->astGroup[0].ptrDst);

/*
      cout<<endl<<endl<<"CfgGen_ServiceNvM";
      for(
         uint16 u16IndexLoop = 0;
                u16IndexLoop < sizeof(CfgGen_ServiceNvM);
                u16IndexLoop ++
      ){
         if(0 == u16IndexLoop%18){
            printf("\n:");
         }
         printf(" %2.2X", ((uint8*)&CfgGen_ServiceNvM)[u16IndexLoop]);
      }
*/

#else
#endif

#if(STD_ON == ServiceNvM_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceNvM_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICENVM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::DeInitFunction(
   void
){
#if(STD_ON == ServiceNvM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceNvM_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceNvM_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICENVM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::MainFunction(
   void
){
#if(STD_ON == ServiceNvM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      //ServiceEcuM.CB_NotifyServiceNvMJobEnd();
   }
   else{
#if(STD_ON == ServiceNvM_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICENVM_E_UNINIT
      );
#endif
#if(STD_ON == ServiceNvM_InitCheck)
   }
#endif
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::SetDataIndex(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::GetDataIndex(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::SetBlockProtection(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::GetErrorStatus(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::SetRamBlockStatus(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::SetBlockLockStatus(
   void
){
}

#include "infEcuabMemIf_ServiceNvM.hpp"

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::McalCancelJobs(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->McalCancel();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ReadBlock(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->Read();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::WriteBlock(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->Write();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::RestoreBlockDefaults(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::EraseNvBlock(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::McalCancelWriteAll(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->McalCancel();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::InvalidateNvBlock(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ReadPRAMBlock(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->Read();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::WritePRAMBlock(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->Write();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::RestorePRAMBlockDefaults(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ReadAll(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->Read();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::WriteAll(
   void
){
   lptrConst->ptrinfEcuabMemIf_ServiceNvM->Write();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ValidateAll(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::JobEndNotification(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::JobErrorNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
