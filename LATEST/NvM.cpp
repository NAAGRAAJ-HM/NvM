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
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgAdc.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgBswM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgBswM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgBswM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCan";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCan.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCan.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCan.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCan.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCan.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCanIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanIf.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCanIf.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCanNm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanNm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCanNm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCanSm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanSm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCanSm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCanTp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCanTp.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCanTp.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCom";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCom.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCom.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCom.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCom.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCom.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgComM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgComM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgComM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgComM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgComM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgComM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCry";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCry.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCry.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCry.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCry.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCry.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCryIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCryIf.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCryIf.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgCsm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgCsm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgCsm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgDem";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDem.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgDem.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgDem.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgDem.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgDem.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgDet";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDet.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgDet.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgDet.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgDet.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgDet.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgDio";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDio.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgDio.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgDio.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgDio.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgDio.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgDlt";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgDlt.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgDlt.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgEa";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEa.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgEa.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgEa.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgEa.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgEa.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgEcuM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEcuM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgEcuM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgEep";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEep.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgEep.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgEep.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgEep.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgEep.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgEth";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEth.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgEth.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgEth.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgEth.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgEth.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgEthIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgEthIf.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgEthIf.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFee";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFee.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFee.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFee.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFee.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFee.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFiM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFiM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFiM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFls";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFls.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFls.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFls.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFls.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFls.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFr";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFr.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFr.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFr.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFr.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFr.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFrIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFrIf.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFrIf.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFrNm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFrNm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFrNm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgFrTp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgFrTp.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgFrTp.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgGpt";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgGpt.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgGpt.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgIcu";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgIcu.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgIcu.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgIpduM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgIpduM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgIpduM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgJ1939Tp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgJ1939Tp.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgJ1939Tp.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgLin";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgLin.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgLin.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgLin.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgLin.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgLin.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgLinIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgLinIf.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgLinIf.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgLinTp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgLinTp.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgLinTp.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgMcu";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgMcu.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgMcu.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgMemIf";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgMemIf.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgMemIf.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgNm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgNm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgNm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgNm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgNm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgNm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgNvM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgNvM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgNvM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgOcu";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgOcu.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgOcu.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgOs";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgOs.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgOs.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgOs.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgOs.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgOs.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgPort";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgPort.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgPort.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgPort.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgPort.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgPort.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgPwm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgPwm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgPwm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgRte";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgRte.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgRte.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgRte.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgRte.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgRte.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgSecOC";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSecOC.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgSecOC.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgSokFm";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSokFm.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgSokFm.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgSpi";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSpi.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgSpi.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgStartUp";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgStartUp.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgStartUp.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgStbM";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgStbM.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgStbM.VersionInfo.SwVersionPatch;

      cout<<endl<<endl<<"CfgSwcApplFoc";
      cout<<endl<<"bDevErrorDetect =\t"<<CfgGen_NvM.CfgSwcApplFoc.bDevErrorDetect;
      cout<<endl<<"ArVersionMajor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.ArVersionMajor;
      cout<<endl<<"ArVersionMinor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.ArVersionMinor;
      cout<<endl<<"IDVendor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.IDVendor;
      cout<<endl<<"IDModule =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.IDModule;
      cout<<endl<<"IDInstance =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.IDInstance;
      cout<<endl<<"SwVersionMajor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.SwVersionMajor;
      cout<<endl<<"SwVersionMinor =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.SwVersionMinor;
      cout<<endl<<"SwVersionPatch =\t"<<CfgGen_NvM.CfgSwcApplFoc.VersionInfo.SwVersionPatch;

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

