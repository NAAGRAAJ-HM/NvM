/******************************************************************************/
/* File   : NvM.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "NvM.hpp"
#include "infNvM_Imp.hpp"

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

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_NvM, NVM_VAR) NvM;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#include <cstring>
#include "CfgGen.hpp"
FUNC(void, NVM_CODE) module_NvM::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, NVM_CONFIG_DATA, NVM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == NvM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == NvM_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }

      if(FALSE){
         memcpy(
               (      void*)&CfgGen_NvM
            ,  (const void*)&CfgGen_Fls
            ,  sizeof(CfgGen_Type)
         );
      }
      else{
         memcpy(
               (      void*)&CfgGen_NvM
            ,  (const void*)&PBcfgGen_ROM
            ,  sizeof(CfgGen_Type)
         );
      }

#if(STD_ON == _ReSIM)
      cout<<endl<<endl<<"CfgAdc";
      printf("\nCfgGen_NvM.CfgAdc.bDevErrorDetect              = %d", CfgGen_NvM.CfgAdc.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgBswM";
      printf("\nCfgGen_NvM.CfgBswM.bDevErrorDetect             = %d", CfgGen_NvM.CfgBswM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCan";
      printf("\nCfgGen_NvM.CfgCan.bDevErrorDetect              = %d", CfgGen_NvM.CfgCan.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCan.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgCan.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCanIf";
      printf("\nCfgGen_NvM.CfgCanIf.bDevErrorDetect            = %d", CfgGen_NvM.CfgCanIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCanNm";
      printf("\nCfgGen_NvM.CfgCanNm.bDevErrorDetect            = %d", CfgGen_NvM.CfgCanNm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCanSm";
      printf("\nCfgGen_NvM.CfgCanSm.bDevErrorDetect            = %d", CfgGen_NvM.CfgCanSm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCanTp";
      printf("\nCfgGen_NvM.CfgCanTp.bDevErrorDetect            = %d", CfgGen_NvM.CfgCanTp.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCom";
      printf("\nCfgGen_NvM.CfgCom.bDevErrorDetect              = %d", CfgGen_NvM.CfgCom.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCom.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgCom.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgComM";
      printf("\nCfgGen_NvM.CfgComM.bDevErrorDetect             = %d", CfgGen_NvM.CfgComM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgComM.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgComM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCry";
      printf("\nCfgGen_NvM.CfgCry.bDevErrorDetect              = %d", CfgGen_NvM.CfgCry.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCry.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgCry.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCryIf";
      printf("\nCfgGen_NvM.CfgCryIf.bDevErrorDetect            = %d", CfgGen_NvM.CfgCryIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgCsm";
      printf("\nCfgGen_NvM.CfgCsm.bDevErrorDetect              = %d", CfgGen_NvM.CfgCsm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgDem";
      printf("\nCfgGen_NvM.CfgDem.bDevErrorDetect              = %d", CfgGen_NvM.CfgDem.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgDem.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgDem.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgDet";
      printf("\nCfgGen_NvM.CfgDet.bDevErrorDetect              = %d", CfgGen_NvM.CfgDet.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgDet.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgDet.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgDio";
      printf("\nCfgGen_NvM.CfgDio.bDevErrorDetect              = %d", CfgGen_NvM.CfgDio.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgDio.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgDio.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgDlt";
      printf("\nCfgGen_NvM.CfgDlt.bDevErrorDetect              = %d", CfgGen_NvM.CfgDlt.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEa";
      printf("\nCfgGen_NvM.CfgEa.bDevErrorDetect               = %d", CfgGen_NvM.CfgEa.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8ArVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8ArVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8IDVendor        = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8IDModule        = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8IDInstance      = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8SwVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8SwVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgEa.VersionInfo.u8SwVersionPatch  = 0x%2.2X", CfgGen_NvM.CfgEa.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEcuM";
      printf("\nCfgGen_NvM.CfgEcuM.bDevErrorDetect             = %d", CfgGen_NvM.CfgEcuM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEep";
      printf("\nCfgGen_NvM.CfgEep.bDevErrorDetect              = %d", CfgGen_NvM.CfgEep.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgEep.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgEep.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEth";
      printf("\nCfgGen_NvM.CfgEth.bDevErrorDetect              = %d", CfgGen_NvM.CfgEth.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgEth.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgEth.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgEthIf";
      printf("\nCfgGen_NvM.CfgEthIf.bDevErrorDetect            = %d", CfgGen_NvM.CfgEthIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFee";
      printf("\nCfgGen_NvM.CfgFee.bDevErrorDetect              = %d", CfgGen_NvM.CfgFee.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFee.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgFee.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFiM";
      printf("\nCfgGen_NvM.CfgFiM.bDevErrorDetect              = %d", CfgGen_NvM.CfgFiM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFls";
      printf("\nCfgGen_NvM.CfgFls.bDevErrorDetect              = %d", CfgGen_NvM.CfgFls.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFls.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgFls.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFr";
      printf("\nCfgGen_NvM.CfgFr.bDevErrorDetect               = %d", CfgGen_NvM.CfgFr.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8ArVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8ArVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8IDVendor        = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8IDModule        = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8IDInstance      = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8SwVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8SwVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFr.VersionInfo.u8SwVersionPatch  = 0x%2.2X", CfgGen_NvM.CfgFr.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFrIf";
      printf("\nCfgGen_NvM.CfgFrIf.bDevErrorDetect             = %d", CfgGen_NvM.CfgFrIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFrNm";
      printf("\nCfgGen_NvM.CfgFrNm.bDevErrorDetect             = %d", CfgGen_NvM.CfgFrNm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgFrTp";
      printf("\nCfgGen_NvM.CfgFrTp.bDevErrorDetect             = %d", CfgGen_NvM.CfgFrTp.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgGpt";
      printf("\nCfgGen_NvM.CfgGpt.bDevErrorDetect              = %d", CfgGen_NvM.CfgGpt.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgIcu";
      printf("\nCfgGen_NvM.CfgIcu.bDevErrorDetect              = %d", CfgGen_NvM.CfgIcu.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgIpduM";
      printf("\nCfgGen_NvM.CfgIpduM.bDevErrorDetect            = %d", CfgGen_NvM.CfgIpduM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgJ1939Tp";
      printf("\nCfgGen_NvM.CfgJ1939Tp.bDevErrorDetect          = %d", CfgGen_NvM.CfgJ1939Tp.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8ArVersionMa= 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8ArVersionMi= 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDVendor   = 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDModule   = 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDInstance = 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionMa= 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionMi= 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionPa= 0x%2.2X", CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgLin";
      printf("\nCfgGen_NvM.CfgLin.bDevErrorDetect              = %d", CfgGen_NvM.CfgLin.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgLin.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgLin.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgLinIf";
      printf("\nCfgGen_NvM.CfgLinIf.bDevErrorDetect            = %d", CfgGen_NvM.CfgLinIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgLinTp";
      printf("\nCfgGen_NvM.CfgLinTp.bDevErrorDetect            = %d", CfgGen_NvM.CfgLinTp.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMcu";
      printf("\nCfgGen_NvM.CfgMcu.bDevErrorDetect              = %d", CfgGen_NvM.CfgMcu.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgMemIf";
      printf("\nCfgGen_NvM.CfgMemIf.bDevErrorDetect            = %d", CfgGen_NvM.CfgMemIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgNm";
      printf("\nCfgGen_NvM.CfgNm.bDevErrorDetect               = %d", CfgGen_NvM.CfgNm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8ArVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8ArVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8IDVendor        = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8IDModule        = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8IDInstance      = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8SwVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8SwVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgNm.VersionInfo.u8SwVersionPatch  = 0x%2.2X", CfgGen_NvM.CfgNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgNvM";
      printf("\nCfgGen_NvM.CfgNvM.bDevErrorDetect              = %d", CfgGen_NvM.CfgNvM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgOcu";
      printf("\nCfgGen_NvM.CfgOcu.bDevErrorDetect              = %d", CfgGen_NvM.CfgOcu.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgOs";
      printf("\nCfgGen_NvM.CfgOs.bDevErrorDetect               = %d", CfgGen_NvM.CfgOs.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8ArVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8ArVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8IDVendor        = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8IDModule        = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8IDInstance      = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8SwVersionMajor  = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8SwVersionMinor  = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgOs.VersionInfo.u8SwVersionPatch  = 0x%2.2X", CfgGen_NvM.CfgOs.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgPort";
      printf("\nCfgGen_NvM.CfgPort.bDevErrorDetect             = %d", CfgGen_NvM.CfgPort.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgPort.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgPort.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgPwm";
      printf("\nCfgGen_NvM.CfgPwm.bDevErrorDetect              = %d", CfgGen_NvM.CfgPwm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgRte";
      printf("\nCfgGen_NvM.CfgRte.bDevErrorDetect              = %d", CfgGen_NvM.CfgRte.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgRte.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgRte.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgSecOC";
      printf("\nCfgGen_NvM.CfgSecOC.bDevErrorDetect            = %d", CfgGen_NvM.CfgSecOC.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgSokFm";
      printf("\nCfgGen_NvM.CfgSokFm.bDevErrorDetect            = %d", CfgGen_NvM.CfgSokFm.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8ArVersionMajo= 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8ArVersionMino= 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8IDVendor     = 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8IDModule     = 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8IDInstance   = 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionMajo= 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionMino= 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionPatc= 0x%2.2X", CfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgSpi";
      printf("\nCfgGen_NvM.CfgSpi.bDevErrorDetect              = %d", CfgGen_NvM.CfgSpi.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgStartUp";
      printf("\nCfgGen_NvM.CfgStartUp.bDevErrorDetect          = %d", CfgGen_NvM.CfgStartUp.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8ArVersionMa= 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8ArVersionMi= 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8IDVendor   = 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8IDModule   = 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8IDInstance = 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionMa= 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionMi= 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionPa= 0x%2.2X", CfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgStbM";
      printf("\nCfgGen_NvM.CfgStbM.bDevErrorDetect             = %d", CfgGen_NvM.CfgStbM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8ArVersionMajor= 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8ArVersionMinor= 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8IDVendor      = 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8IDModule      = 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8IDInstance    = 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionMajor= 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionMinor= 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionPatch= 0x%2.2X", CfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgSwcApplFoc";
      printf("\nCfgGen_NvM.CfgSwcApplFoc.bDevErrorDetect       = %d", CfgGen_NvM.CfgSwcApplFoc.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8ArVersio= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8ArVersio= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDVendor= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDModule= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDInstan= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersio= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersio= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersio= 0x%2.2X", CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgSwcServiceEcuM";
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.bDevErrorDetect              = %d", CfgGen_NvM.CfgSwcServiceEcuM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgSwcServiceEcuM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgSwcServiceOs";
      printf("\nCfgGen_NvM.CfgSwcServiceOs.bDevErrorDetect              = %d", CfgGen_NvM.CfgSwcServiceOs.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgSwcServiceOs.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgVkms";
      printf("\nCfgGen_NvM.CfgVkms.bDevErrorDetect              = %d", CfgGen_NvM.CfgVkms.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgVkms.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgVkms.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgWdg";
      printf("\nCfgGen_NvM.CfgWdg.bDevErrorDetect              = %d", CfgGen_NvM.CfgWdg.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgWdg.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgWdg.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgWdgIf";
      printf("\nCfgGen_NvM.CfgWdgIf.bDevErrorDetect              = %d", CfgGen_NvM.CfgWdgIf.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgWdgIf.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgWdgIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"CfgWdgM";
      printf("\nCfgGen_NvM.CfgWdgM.bDevErrorDetect              = %d", CfgGen_NvM.CfgWdgM.bDevErrorDetect);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8ArVersionMajor = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8ArVersionMajor);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8ArVersionMinor = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8ArVersionMinor);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8IDVendor       = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8IDVendor);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8IDModule       = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8IDModule);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8IDInstance     = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8IDInstance);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8SwVersionMajor = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8SwVersionMajor);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8SwVersionMinor = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8SwVersionMinor);
      printf("\nCfgGen_NvM.CfgWdgM.VersionInfo.u8SwVersionPatch = 0x%2.2X", CfgGen_NvM.CfgWdgM.VersionInfo.u8SwVersionPatch);

#else
#endif

#if(STD_ON == NvM_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  NVM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::DeInitFunction(
   void
){
#if(STD_ON == NvM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == NvM_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  NVM_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::MainFunction(
   void
){
#if(STD_ON == NvM_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
      //EcuM.CB_NotifyNvMJobEnd();
   }
   else{
#if(STD_ON == NvM_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  NVM_E_UNINIT
      );
#endif
#if(STD_ON == NvM_InitCheck)
   }
#endif
}

FUNC(void, NVM_CODE) module_NvM::SetDataIndex(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::GetDataIndex(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::SetBlockProtection(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::GetErrorStatus(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::SetRamBlockStatus(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::SetBlockLockStatus(
   void
){
}

#include "infMemIf_NvM.hpp"

FUNC(void, NVM_CODE) module_NvM::CancelJobs(
   void
){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) module_NvM::ReadBlock(
   void
){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) module_NvM::WriteBlock(
   void
){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) module_NvM::RestoreBlockDefaults(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::EraseNvBlock(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::CancelWriteAll(
   void
){
   gptrinfMemIf_NvM->Cancel();
}

FUNC(void, NVM_CODE) module_NvM::InvalidateNvBlock(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::ReadPRAMBlock(
   void
){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) module_NvM::WritePRAMBlock(
   void
){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) module_NvM::RestorePRAMBlockDefaults(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::ReadAll(
   void
){
   gptrinfMemIf_NvM->Read();
}

FUNC(void, NVM_CODE) module_NvM::WriteAll(
   void
){
   gptrinfMemIf_NvM->Write();
}

FUNC(void, NVM_CODE) module_NvM::ValidateAll(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::JobEndNotification(
   void
){
}

FUNC(void, NVM_CODE) module_NvM::JobErrorNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

