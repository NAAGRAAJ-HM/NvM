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
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgAdc.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgBswM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgBswM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCan";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCan.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCan.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCanIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanIf.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCanNm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanNm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCanSm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanSm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCanTp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanTp.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCom";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCom.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCom.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgComM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgComM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgComM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCry";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCry.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCry.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCryIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCryIf.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgCsm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCsm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgDem";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDem.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgDem.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgDet";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDet.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgDet.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgDio";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDio.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgDio.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgDlt";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDlt.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgEa";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEa.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgEa.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgEcuM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEcuM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgEep";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEep.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgEep.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgEth";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEth.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgEth.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgEthIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEthIf.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFee";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFee.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFee.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFiM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFiM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFls";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFls.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFls.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFr";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFr.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFr.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFrIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFrIf.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFrNm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFrNm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgFrTp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFrTp.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgGpt";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgGpt.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgIcu";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgIcu.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgIpduM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgIpduM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgJ1939Tp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgJ1939Tp.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgLin";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgLin.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgLin.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgLinIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgLinIf.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgLinTp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgLinTp.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgMcu";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgMcu.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgMemIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgMemIf.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgNm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgNm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgNm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgNvM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgNvM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgOcu";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgOcu.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgOs";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgOs.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgOs.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgPort";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgPort.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgPort.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgPwm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgPwm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgRte";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgRte.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgRte.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgSecOC";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSecOC.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgSokFm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSokFm.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgSpi";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSpi.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgStartUp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgStartUp.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgStbM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgStbM.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.u8SwVersionPatch;

      cout<<endl<<endl<<"CfgSwcApplFoc";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSwcApplFoc.bDevErrorDetect;
      cout<<endl<<"u8ArVersionMajor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8ArVersionMajor;
      cout<<endl<<"u8ArVersionMinor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8ArVersionMinor;
      cout<<endl<<"u8IDVendor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDVendor;
      cout<<endl<<"u8IDModule =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDModule;
      cout<<endl<<"u8IDInstance =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8IDInstance;
      cout<<endl<<"u8SwVersionMajor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersionMajor;
      cout<<endl<<"u8SwVersionMinor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersionMinor;
      cout<<endl<<"u8SwVersionPatch =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.u8SwVersionPatch;

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

