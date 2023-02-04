/******************************************************************************/
/* File   : ServiceNvM.cpp                                                    */
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
#define PBcfgGen_DefaultInit                                                   \
      {ApplSwcFoc_DevErrorDetect,     {APPLSWCFOC_AR_RELEASE_VERSION_MAJOR,     APPLSWCFOC_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ProjectARA_DevErrorDetect,     {RTE_AR_RELEASE_VERSION_MAJOR,            RTE_AR_RELEASE_VERSION_MINOR,            0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceBswM_DevErrorDetect,    {SERVICEBSWM_AR_RELEASE_VERSION_MAJOR,    SERVICEBSWM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceCanNm_DevErrorDetect,   {SERVICECANNM_AR_RELEASE_VERSION_MAJOR,   SERVICECANNM_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceCanSm_DevErrorDetect,   {SERVICECANSM_AR_RELEASE_VERSION_MAJOR,   SERVICECANSM_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceCom_DevErrorDetect,     {SERVICECOM_AR_RELEASE_VERSION_MAJOR,     SERVICECOM_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceComM_DevErrorDetect,    {SERVICECOMM_AR_RELEASE_VERSION_MAJOR,    SERVICECOMM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceCsm_DevErrorDetect,     {SERVICECSM_AR_RELEASE_VERSION_MAJOR,     SERVICECSM_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceDcm_DevErrorDetect,     {SERVICEDCM_AR_RELEASE_VERSION_MAJOR,     SERVICEDCM_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceDem_DevErrorDetect,     {SERVICEDEM_AR_RELEASE_VERSION_MAJOR,     SERVICEDEM_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceDet_DevErrorDetect,     {SERVICEDET_AR_RELEASE_VERSION_MAJOR,     SERVICEDET_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceDlt_DevErrorDetect,     {SERVICEDLT_AR_RELEASE_VERSION_MAJOR,     SERVICEDLT_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceEcuM_DevErrorDetect,    {SERVICEECUM_AR_RELEASE_VERSION_MAJOR,    SERVICEECUM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceFiM_DevErrorDetect,     {SERVICEFIM_AR_RELEASE_VERSION_MAJOR,     SERVICEFIM_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceFrNm_DevErrorDetect,    {SERVICEFRNM_AR_RELEASE_VERSION_MAJOR,    SERVICEFRNM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceIpduM_DevErrorDetect,   {SERVICEIPDUM_AR_RELEASE_VERSION_MAJOR,   SERVICEIPDUM_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceNm_DevErrorDetect,      {SERVICENM_AR_RELEASE_VERSION_MAJOR,      SERVICENM_AR_RELEASE_VERSION_MINOR,      0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceNvM_DevErrorDetect,     {SERVICENVM_AR_RELEASE_VERSION_MAJOR,     SERVICENVM_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceOs_DevErrorDetect,      {SERVICEOS_AR_RELEASE_VERSION_MAJOR,      SERVICEOS_AR_RELEASE_VERSION_MINOR,      0x00,0xFF,0x01,'0','1','0'}} \
   ,  {                                                                        \
            ServicePduR_DevErrorDetect                                         \
         ,  {                                                                  \
                  SERVICEPDUR_AR_RELEASE_VERSION_MAJOR                      \
               ,  SERVICEPDUR_AR_RELEASE_VERSION_MINOR                      \
               ,  0x00                                                         \
               ,  0xFF                                                         \
               ,  0x01                                                         \
               ,  '0'                                                          \
               ,  '1'                                                          \
               ,  '0'                                                          \
            }                                                                  \
         ,  {                                                                  \
                  1                                                            \
               ,  {                                                            \
                        &ServicePduRClient_ServiceDcm                          \
/*                   ,  &ServicePduRClient_ServiceCom */                       \
                  }                                                            \
               ,  0                                                            \
               ,  0                                                            \
            }                                                                  \
      }                                                                        \
   ,  {ServiceSchM_DevErrorDetect,    {SERVICESCHM_AR_RELEASE_VERSION_MAJOR,    SERVICESCHM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceSecOC_DevErrorDetect,   {SERVICESECOC_AR_RELEASE_VERSION_MAJOR,   SERVICESECOC_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceSokFm_DevErrorDetect,   {SERVICESOKFM_AR_RELEASE_VERSION_MAJOR,   SERVICESOKFM_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceStartUp_DevErrorDetect, {SERVICESTARTUP_AR_RELEASE_VERSION_MAJOR, SERVICESTARTUP_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceStbM_DevErrorDetect,    {SERVICESTBM_AR_RELEASE_VERSION_MAJOR,    SERVICESTBM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceSwcEcuM_DevErrorDetect, {SERVICESWCECUM_AR_RELEASE_VERSION_MAJOR, SERVICESWCECUM_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceSwcOs_DevErrorDetect,   {SERVICESWCOS_AR_RELEASE_VERSION_MAJOR,   SERVICESWCOS_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceVkms_DevErrorDetect,    {SERVICEVKMS_AR_RELEASE_VERSION_MAJOR,    SERVICEVKMS_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {ServiceWdgM_DevErrorDetect,    {SERVICEWDGM_AR_RELEASE_VERSION_MAJOR,    SERVICEWDGM_AR_RELEASE_VERSION_MINOR,    0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabCanIf_DevErrorDetect,     {ECUABCANIF_AR_RELEASE_VERSION_MAJOR,     ECUABCANIF_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabCanTp_DevErrorDetect,     {ECUABCANTP_AR_RELEASE_VERSION_MAJOR,     ECUABCANTP_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabCryIf_DevErrorDetect,     {ECUABCRYIF_AR_RELEASE_VERSION_MAJOR,     ECUABCRYIF_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabEa_DevErrorDetect,        {ECUABEA_AR_RELEASE_VERSION_MAJOR,        ECUABEA_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabEthIf_DevErrorDetect,     {ECUABETHIF_AR_RELEASE_VERSION_MAJOR,     ECUABETHIF_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabFee_DevErrorDetect,       {ECUABFEE_AR_RELEASE_VERSION_MAJOR,       ECUABFEE_AR_RELEASE_VERSION_MINOR,       0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabFrIf_DevErrorDetect,      {ECUABFRIF_AR_RELEASE_VERSION_MAJOR,      ECUABFRIF_AR_RELEASE_VERSION_MINOR,      0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabFrTp_DevErrorDetect,      {ECUABFRTP_AR_RELEASE_VERSION_MAJOR,      ECUABFRTP_AR_RELEASE_VERSION_MINOR,      0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabJ1939Tp_DevErrorDetect,   {ECUABJ1939TP_AR_RELEASE_VERSION_MAJOR,   ECUABJ1939TP_AR_RELEASE_VERSION_MINOR,   0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabLinIf_DevErrorDetect,     {ECUABLINIF_AR_RELEASE_VERSION_MAJOR,     ECUABLINIF_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabLinTp_DevErrorDetect,     {ECUABLINTP_AR_RELEASE_VERSION_MAJOR,     ECUABLINTP_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabMemIf_DevErrorDetect,     {ECUABMEMIF_AR_RELEASE_VERSION_MAJOR,     ECUABMEMIF_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {EcuabWdgIf_DevErrorDetect,     {ECUABWDGIF_AR_RELEASE_VERSION_MAJOR,     ECUABWDGIF_AR_RELEASE_VERSION_MINOR,     0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalAdc_DevErrorDetect,        {MCALADC_AR_RELEASE_VERSION_MAJOR,        MCALADC_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalCan_DevErrorDetect,        {MCALCAN_AR_RELEASE_VERSION_MAJOR,        MCALCAN_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalCry_DevErrorDetect,        {MCALCRY_AR_RELEASE_VERSION_MAJOR,        MCALCRY_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalDio_DevErrorDetect,        {MCALDIO_AR_RELEASE_VERSION_MAJOR,        MCALDIO_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalEep_DevErrorDetect,        {MCALEEP_AR_RELEASE_VERSION_MAJOR,        MCALEEP_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalEth_DevErrorDetect,        {MCALETH_AR_RELEASE_VERSION_MAJOR,        MCALETH_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalFls_DevErrorDetect,        {MCALFLS_AR_RELEASE_VERSION_MAJOR,        MCALFLS_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalFr_DevErrorDetect,         {MCALFR_AR_RELEASE_VERSION_MAJOR,         MCALFR_AR_RELEASE_VERSION_MINOR,         0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalGpt_DevErrorDetect,        {MCALGPT_AR_RELEASE_VERSION_MAJOR,        MCALGPT_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalIcu_DevErrorDetect,        {MCALICU_AR_RELEASE_VERSION_MAJOR,        MCALICU_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalLin_DevErrorDetect,        {MCALLIN_AR_RELEASE_VERSION_MAJOR,        MCALLIN_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalMcu_DevErrorDetect,        {MCALMCU_AR_RELEASE_VERSION_MAJOR,        MCALMCU_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalOcu_DevErrorDetect,        {MCALOCU_AR_RELEASE_VERSION_MAJOR,        MCALOCU_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalPort_DevErrorDetect,       {MCALPORT_AR_RELEASE_VERSION_MAJOR,       MCALPORT_AR_RELEASE_VERSION_MINOR,       0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalPwm_DevErrorDetect,        {MCALPWM_AR_RELEASE_VERSION_MAJOR,        MCALPWM_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalSpi_DevErrorDetect,        {MCALSPI_AR_RELEASE_VERSION_MAJOR,        MCALSPI_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \
   ,  {McalWdg_DevErrorDetect,        {MCALWDG_AR_RELEASE_VERSION_MAJOR,        MCALWDG_AR_RELEASE_VERSION_MINOR,        0x00,0xFF,0x01,'0','1','0'}} \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
TypeClient ServicePduRClient_ServiceDcm; //TBD:  = {0}; actual realization

const NvM_BlocksNv_Type NvM_BlocksNvRom = {
   PBcfgGen_DefaultInit
};

const NvM_BlocksNv_Type Fls_Blocks = { //TBD: move to Fls
   PBcfgGen_DefaultInit
};

const NvM_BlocksRom_Type NvM_BlocksRom = {
   NvM_InitBlocksRom_ApplSwcFoc
   NvM_InitBlocksRom_ServiceRte
   NvM_InitBlocksRom_ServiceBswM
   NvM_InitBlocksRom_ServiceCanNm
   NvM_InitBlocksRom_ServiceCanSm
   NvM_InitBlocksRom_ServiceCom
   NvM_InitBlocksRom_ServiceComM
   NvM_InitBlocksRom_ServiceCsm
   NvM_InitBlocksRom_ServiceDcm
   NvM_InitBlocksRom_ServiceDem
   NvM_InitBlocksRom_ServiceDet
   NvM_InitBlocksRom_ServiceDlt
   NvM_InitBlocksRom_ServiceEcuM
   NvM_InitBlocksRom_ServiceFiM
   NvM_InitBlocksRom_ServiceFrNm
   NvM_InitBlocksRom_ServiceIpduM
   NvM_InitBlocksRom_ServiceNm
   NvM_InitBlocksRom_ServiceNvM
   NvM_InitBlocksRom_ServiceOs
   NvM_InitBlocksRom_ServicePduR
   NvM_InitBlocksRom_ServiceSchM
   NvM_InitBlocksRom_ServiceSecOC
   NvM_InitBlocksRom_ServiceSokFm
   NvM_InitBlocksRom_ServiceStartUp
   NvM_InitBlocksRom_ServiceStbM
   NvM_InitBlocksRom_ServiceSwcEcuM
   NvM_InitBlocksRom_ServiceSwcIoHwAb
   NvM_InitBlocksRom_ServiceSwcOs
   NvM_InitBlocksRom_ServiceVkms
   NvM_InitBlocksRom_ServiceWdgM
   NvM_InitBlocksRom_EcuabCanIf
   NvM_InitBlocksRom_EcuabCanTp
   NvM_InitBlocksRom_EcuabCryIf
   NvM_InitBlocksRom_EcuabEa
   NvM_InitBlocksRom_EcuabEthIf
   NvM_InitBlocksRom_EcuabFee
   NvM_InitBlocksRom_EcuabFrIf
   NvM_InitBlocksRom_EcuabFrTp
   NvM_InitBlocksRom_EcuabJ1939Tp
   NvM_InitBlocksRom_EcuabLinIf
   NvM_InitBlocksRom_EcuabLinTp
   NvM_InitBlocksRom_EcuabMemIf
   NvM_InitBlocksRom_EcuabWdgIf
   NvM_InitBlocksRom_McalAdc
   NvM_InitBlocksRom_McalCan
   NvM_InitBlocksRom_McalCry
   NvM_InitBlocksRom_McalDio
   NvM_InitBlocksRom_McalEep
   NvM_InitBlocksRom_McalEth
   NvM_InitBlocksRom_McalFls
   NvM_InitBlocksRom_McalFr
   NvM_InitBlocksRom_McalGpt
   NvM_InitBlocksRom_McalIcu
   NvM_InitBlocksRom_McalLin
   NvM_InitBlocksRom_McalMcu
   NvM_InitBlocksRom_McalOcu
   NvM_InitBlocksRom_McalPort
   NvM_InitBlocksRom_McalPwm
   NvM_InitBlocksRom_McalSpi
   NvM_InitBlocksRom_McalWdg
};

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_ServiceNvM, SERVICENVM_VAR) ServiceNvM;
NvM_BlocksNv_Type NvM_BlocksNvRam; //TBD: move as private data


/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICENVM_CODE) module_ServiceNvM::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICENVM_CONST,       SERVICENVM_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICENVM_CONFIG_DATA, SERVICENVM_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceNvM_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
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
               (      void*)&NvM_BlocksNvRam
            ,  (const void*)&Fls_Blocks
            ,  sizeof(NvM_BlocksNv_Type)
         );
      }
      else{
         memcpy(
               (      void*)&NvM_BlocksNvRam
            ,  (const void*)&NvM_BlocksNvRom
            ,  sizeof(NvM_BlocksNv_Type)
         );
      }

#if(STD_ON == _ReSIM)
/*
      cout<<endl<<endl<<"NvM_BlocksNv_McalAdc";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalAdc.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceBswM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceBswM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalCan";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCan.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabCanIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceCanNm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceCanSm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCanSm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabCanTp";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCanTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceCom";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCom.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceComM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceComM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalCry";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalCry.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabCryIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabCryIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceCsm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceCsm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceDcm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDcm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceDem";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDem.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceDet";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDet.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalDio";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalDio.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceDlt";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceDlt.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabEa";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.bDevErrorDetect                          = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8ArVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8ArVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8IDVendor                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8IDModule                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8IDInstance                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8SwVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8SwVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8SwVersionPatch             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEa.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceEcuM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceEcuM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalEep";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEep.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalEth";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalEth.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabEthIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabEthIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabFee";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFee.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceFiM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFiM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalFls";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFls.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalFr";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.bDevErrorDetect                          = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8ArVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8ArVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8IDVendor                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8IDModule                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8IDInstance                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8SwVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8SwVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8SwVersionPatch             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalFr.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabFrIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceFrNm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceFrNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabFrTp";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabFrTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalGpt";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalGpt.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalIcu";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalIcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceIpduM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceIpduM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabJ1939Tp";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.bDevErrorDetect                     = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8ArVersionMajor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8ArVersionMinor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8IDVendor              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8IDModule              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8IDInstance            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8SwVersionMajor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8SwVersionMinor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8SwVersionPatch        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabJ1939Tp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalLin";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalLin.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabLinIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabLinTp";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabLinTp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalMcu";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalMcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabMemIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabMemIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceNm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.bDevErrorDetect                          = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8ArVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8ArVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8IDVendor                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8IDModule                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8IDInstance                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8SwVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8SwVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8SwVersionPatch             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceNvM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceNvM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalOcu";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalOcu.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceOs";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.bDevErrorDetect                          = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8ArVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8ArVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8IDVendor                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8IDModule                   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8IDInstance                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8SwVersionMajor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8SwVersionMinor             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8SwVersionPatch             = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceOs.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalPort";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPort.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalPwm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalPwm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ProjectARA";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ProjectARA.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceSchM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSchM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceSecOC";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSecOC.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceSokFm";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSokFm.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalSpi";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalSpi.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceStartUp";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.bDevErrorDetect                     = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8ArVersionMajor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8ArVersionMinor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8IDVendor              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8IDModule              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8IDInstance            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8SwVersionMajor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8SwVersionMinor        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8SwVersionPatch        = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStartUp.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceStbM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceStbM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ApplSwcFoc";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.bDevErrorDetect                  = %d", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8ArVersionMajor     = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8ArVersionMinor     = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8IDVendor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8IDModule           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8IDInstance         = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8SwVersionMajor     = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8SwVersionMinor     = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8SwVersionPatch     = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ApplSwcFoc.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceSwcEcuM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.bDevErrorDetect              = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8ArVersionMajor = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8ArVersionMinor = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8IDVendor       = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8IDModule       = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8IDInstance     = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8SwVersionMajor = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8SwVersionMinor = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8SwVersionPatch = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcEcuM.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceSwcOs";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.bDevErrorDetect                = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8ArVersionMajor   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8ArVersionMinor   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8IDVendor         = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8IDModule         = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8IDInstance       = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8SwVersionMajor   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8SwVersionMinor   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8SwVersionPatch   = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceSwcOs.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceVkms";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceVkms.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_McalWdg";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.bDevErrorDetect                         = %d", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8ArVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8ArVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8IDVendor                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8IDModule                  = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8IDInstance                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8SwVersionMajor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8SwVersionMinor            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8SwVersionPatch            = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_McalWdg.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_EcuabWdgIf";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.bDevErrorDetect                       = %d", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8ArVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8ArVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8IDVendor                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8IDModule                = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8IDInstance              = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8SwVersionMajor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8SwVersionMinor          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8SwVersionPatch          = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_EcuabWdgIf.VersionInfo.u8SwVersionPatch);

      cout<<endl<<endl<<"NvM_BlocksNv_ServiceWdgM";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServiceWdgM.VersionInfo.u8SwVersionPatch);
*/
/*
      cout<<endl<<endl<<"NvM_BlocksNv_ServicePduR";
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.bDevErrorDetect                        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.bDevErrorDetect);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8ArVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8ArVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8ArVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8ArVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8IDVendor                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8IDVendor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8IDModule                 = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8IDModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8IDInstance               = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8IDInstance);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8SwVersionMajor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8SwVersionMajor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8SwVersionMinor           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8SwVersionMinor);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8SwVersionPatch           = 0x%2.2X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.VersionInfo.u8SwVersionPatch);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.Id                                = 0x%4.4X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.Id);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bUpperModule            = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bUpperModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bLowerModule            = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bLowerModule);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCommunicationInterface = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCommunicationInterface);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTransportProtocol      = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTransportProtocol);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTransmit               = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTransmit);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTransmitTp             = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTransmitTp);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTxConfirmation         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTxConfirmation);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTxConfirmationTp       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTxConfirmationTp);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bRxIndication           = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bRxIndication);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bRxIndicationTp         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bRxIndicationTp);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCancelTransmit         = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCancelTransmit);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCancelReceive          = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCancelReceive);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCopyTxData             = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCopyTxData);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCopyRxData             = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bCopyRxData);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTriggerTransmit        = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bTriggerTransmit);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bReTransmition          = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bReTransmition);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bStartOfReception       = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bStartOfReception);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bUseTag                 = %d", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrClients[0]->bUseTag);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.u16CntMaxRoutingPathGroup         = 0x%4.4X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.u16CntMaxRoutingPathGroup);
      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups                        = 0x%p", (void*)NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups);
*/
//      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->Id                   = 0x%4.4X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->Id);
//      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->u16CntMaxRoutingPath = 0x%4.4X", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->u16CntMaxRoutingPath);
//      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->astGroup[0].ptrSrc   = 0x%p", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->astGroup[0].ptrSrc);
//      printf("\nNvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->astGroup[0].ptrDst   = 0x%p", NvM_BlocksNvRam.NvM_BlocksNv_ServicePduR.Core.aptrGroups[0]->astGroup[0].ptrDst);

/*
      cout<<endl<<endl<<"NvM_BlocksNvRam";
      for(
         uint16 u16IndexLoop = 0;
                u16IndexLoop < sizeof(NvM_BlocksNvRam);
                u16IndexLoop ++
      ){
         if(0 == u16IndexLoop%18){
            printf("\n:");
         }
         printf(" %2.2X", ((uint8*)&NvM_BlocksNvRam)[u16IndexLoop]);
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
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->McalCancel(); // TBD: OOPS concepts
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ReadBlock(
   void
){
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->Read();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::WriteBlock(
   void
){
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->Write();
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
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->McalCancel();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::InvalidateNvBlock(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ReadPRAMBlock(
   void
){
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->Read();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::WritePRAMBlock(
   void
){
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->Write();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::RestorePRAMBlockDefaults(
   void
){
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::ReadAll(
   void
){
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->Read();
}

FUNC(void, SERVICENVM_CODE) module_ServiceNvM::WriteAll(
   void
){
   ((NvM_BlocksRom_ServiceNvM_Type*)lptrNvMBlocksRom)->ptrinfEcuabMemIf_ServiceNvM->Write();
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
