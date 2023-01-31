#pragma once
/******************************************************************************/
/* File   : infServiceNvM_ServiceEcuM.hpp                                     */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infApplSwcFoc_ServiceNvM_Types.hpp"
#include "infProjectARA_ServiceNvM_Types.hpp"
#include "infServiceBswM_ServiceNvM_Types.hpp"
#include "infServiceCanNm_ServiceNvM_Types.hpp"
#include "infServiceCanSm_ServiceNvM_Types.hpp"
#include "infServiceCom_ServiceNvM_Types.hpp"
#include "infServiceComM_ServiceNvM_Types.hpp"
#include "infServiceCsm_ServiceNvM_Types.hpp"
#include "infServiceDcm_ServiceNvM_Types.hpp"
#include "infServiceDem_ServiceNvM_Types.hpp"
#include "infServiceDet_ServiceNvM_Types.hpp"
#include "infServiceDlt_ServiceNvM_Types.hpp"
#include "infServiceEcuM_ServiceNvM_Types.hpp"
#include "infServiceFiM_ServiceNvM_Types.hpp"
#include "infServiceFrNm_ServiceNvM_Types.hpp"
#include "infServiceIpduM_ServiceNvM_Types.hpp"
#include "infServiceNm_ServiceNvM_Types.hpp"
#include "infServiceNvM_ServiceNvM_Types.hpp"
#include "infServiceOs_ServiceNvM_Types.hpp"
#include "infServicePduR_ServiceNvM_Types.hpp"
#include "infServiceSchM_ServiceNvM_Types.hpp"
#include "infServiceSecOC_ServiceNvM_Types.hpp"
#include "infServiceSokFm_ServiceNvM_Types.hpp"
#include "infServiceStartUp_ServiceNvM_Types.hpp"
#include "infServiceStbM_ServiceNvM_Types.hpp"
#include "infServiceSwcEcuM_ServiceNvM_Types.hpp"
#include "infServiceSwcIoHwAb_ServiceNvM_Types.hpp"
#include "infServiceSwcOs_ServiceNvM_Types.hpp"
#include "infServiceVkms_ServiceNvM_Types.hpp"
#include "infServiceWdgM_ServiceNvM_Types.hpp"
#include "infEcuabCanIf_ServiceNvM_Types.hpp"
#include "infEcuabCanTp_ServiceNvM_Types.hpp"
#include "infEcuabCryIf_ServiceNvM_Types.hpp"
#include "infEcuabEa_ServiceNvM_Types.hpp"
#include "infEcuabEthIf_ServiceNvM_Types.hpp"
#include "infEcuabFee_ServiceNvM_Types.hpp"
#include "infEcuabFrIf_ServiceNvM_Types.hpp"
#include "infEcuabFrTp_ServiceNvM_Types.hpp"
#include "infEcuabJ1939Tp_ServiceNvM_Types.hpp"
#include "infEcuabLinIf_ServiceNvM_Types.hpp"
#include "infEcuabLinTp_ServiceNvM_Types.hpp"
#include "infEcuabMemIf_ServiceNvM_Types.hpp"
#include "infEcuabWdgIf_ServiceNvM_Types.hpp"
#include "infMcalAdc_ServiceNvM_Types.hpp"
#include "infMcalCan_ServiceNvM_Types.hpp"
#include "infMcalCry_ServiceNvM_Types.hpp"
#include "infMcalDio_ServiceNvM_Types.hpp"
#include "infMcalEep_ServiceNvM_Types.hpp"
#include "infMcalEth_ServiceNvM_Types.hpp"
#include "infMcalFls_ServiceNvM_Types.hpp"
#include "infMcalFr_ServiceNvM_Types.hpp"
#include "infMcalGpt_ServiceNvM_Types.hpp"
#include "infMcalIcu_ServiceNvM_Types.hpp"
#include "infMcalLin_ServiceNvM_Types.hpp"
#include "infMcalMcu_ServiceNvM_Types.hpp"
#include "infMcalOcu_ServiceNvM_Types.hpp"
#include "infMcalPort_ServiceNvM_Types.hpp"
#include "infMcalPwm_ServiceNvM_Types.hpp"
#include "infMcalSpi_ServiceNvM_Types.hpp"
#include "infMcalWdg_ServiceNvM_Types.hpp"

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class NvM_BlocksRom_Type{
   public:
      NvM_BlocksRom_ApplSwcFoc_Type       NvM_BlocksRom_ApplSwcFoc;
      NvM_BlocksRom_ProjectARA_Type       NvM_BlocksRom_ProjectARA;
      NvM_BlocksRom_ServiceBswM_Type      NvM_BlocksRom_ServiceBswM;
      NvM_BlocksRom_ServiceCanNm_Type     NvM_BlocksRom_ServiceCanNm;
      NvM_BlocksRom_ServiceCanSm_Type     NvM_BlocksRom_ServiceCanSm;
      NvM_BlocksRom_ServiceCom_Type       NvM_BlocksRom_ServiceCom;
      NvM_BlocksRom_ServiceComM_Type      NvM_BlocksRom_ServiceComM;
      NvM_BlocksRom_ServiceCsm_Type       NvM_BlocksRom_ServiceCsm;
      NvM_BlocksRom_ServiceDcm_Type       NvM_BlocksRom_ServiceDcm;
      NvM_BlocksRom_ServiceDem_Type       NvM_BlocksRom_ServiceDem;
      NvM_BlocksRom_ServiceDet_Type       NvM_BlocksRom_ServiceDet;
      NvM_BlocksRom_ServiceDlt_Type       NvM_BlocksRom_ServiceDlt;
      NvM_BlocksRom_ServiceEcuM_Type      NvM_BlocksRom_ServiceEcuM;
      NvM_BlocksRom_ServiceFiM_Type       NvM_BlocksRom_ServiceFiM;
      NvM_BlocksRom_ServiceFrNm_Type      NvM_BlocksRom_ServiceFrNm;
      NvM_BlocksRom_ServiceIpduM_Type     NvM_BlocksRom_ServiceIpduM;
      NvM_BlocksRom_ServiceNm_Type        NvM_BlocksRom_ServiceNm;
      NvM_BlocksRom_ServiceNvM_Type       NvM_BlocksRom_ServiceNvM;
      NvM_BlocksRom_ServiceOs_Type        NvM_BlocksRom_ServiceOs;
      NvM_BlocksRom_ServicePduR_Type      NvM_BlocksRom_ServicePduR;
      NvM_BlocksRom_ServiceSchM_Type      NvM_BlocksRom_ServiceSchM;
      NvM_BlocksRom_ServiceSecOC_Type     NvM_BlocksRom_ServiceSecOC;
      NvM_BlocksRom_ServiceSokFm_Type     NvM_BlocksRom_ServiceSokFm;
      NvM_BlocksRom_ServiceStartUp_Type   NvM_BlocksRom_ServiceStartUp;
      NvM_BlocksRom_ServiceStbM_Type      NvM_BlocksRom_ServiceStbM;
      NvM_BlocksRom_ServiceSwcEcuM_Type   NvM_BlocksRom_ServiceSwcEcuM;
      NvM_BlocksRom_ServiceSwcIoHwAb_Type NvM_BlocksRom_ServiceSwcIoHwAb;
      NvM_BlocksRom_ServiceSwcOs_Type     NvM_BlocksRom_ServiceSwcOs;
      NvM_BlocksRom_ServiceVkms_Type      NvM_BlocksRom_ServiceVkms;
      NvM_BlocksRom_ServiceWdgM_Type      NvM_BlocksRom_ServiceWdgM;
      NvM_BlocksRom_EcuabCanIf_Type       NvM_BlocksRom_EcuabCanIf;
      NvM_BlocksRom_EcuabCanTp_Type       NvM_BlocksRom_EcuabCanTp;
      NvM_BlocksRom_EcuabCryIf_Type       NvM_BlocksRom_EcuabCryIf;
      NvM_BlocksRom_EcuabEa_Type          NvM_BlocksRom_EcuabEa;
      NvM_BlocksRom_EcuabEthIf_Type       NvM_BlocksRom_EcuabEthIf;
      NvM_BlocksRom_EcuabFee_Type         NvM_BlocksRom_EcuabFee;
      NvM_BlocksRom_EcuabFrIf_Type        NvM_BlocksRom_EcuabFrIf;
      NvM_BlocksRom_EcuabFrTp_Type        NvM_BlocksRom_EcuabFrTp;
      NvM_BlocksRom_EcuabJ1939Tp_Type     NvM_BlocksRom_EcuabJ1939Tp;
      NvM_BlocksRom_EcuabLinIf_Type       NvM_BlocksRom_EcuabLinIf;
      NvM_BlocksRom_EcuabLinTp_Type       NvM_BlocksRom_EcuabLinTp;
      NvM_BlocksRom_EcuabMemIf_Type       NvM_BlocksRom_EcuabMemIf;
      NvM_BlocksRom_EcuabWdgIf_Type       NvM_BlocksRom_EcuabWdgIf;
      NvM_BlocksRom_McalAdc_Type          NvM_BlocksRom_McalAdc;
      NvM_BlocksRom_McalCan_Type          NvM_BlocksRom_McalCan;
      NvM_BlocksRom_McalCry_Type          NvM_BlocksRom_McalCry;
      NvM_BlocksRom_McalDio_Type          NvM_BlocksRom_McalDio;
      NvM_BlocksRom_McalEep_Type          NvM_BlocksRom_McalEep;
      NvM_BlocksRom_McalEth_Type          NvM_BlocksRom_McalEth;
      NvM_BlocksRom_McalFls_Type          NvM_BlocksRom_McalFls;
      NvM_BlocksRom_McalFr_Type           NvM_BlocksRom_McalFr;
      NvM_BlocksRom_McalGpt_Type          NvM_BlocksRom_McalGpt;
      NvM_BlocksRom_McalIcu_Type          NvM_BlocksRom_McalIcu;
      NvM_BlocksRom_McalLin_Type          NvM_BlocksRom_McalLin;
      NvM_BlocksRom_McalMcu_Type          NvM_BlocksRom_McalMcu;
      NvM_BlocksRom_McalOcu_Type          NvM_BlocksRom_McalOcu;
      NvM_BlocksRom_McalPort_Type         NvM_BlocksRom_McalPort;
      NvM_BlocksRom_McalPwm_Type          NvM_BlocksRom_McalPwm;
      NvM_BlocksRom_McalSpi_Type          NvM_BlocksRom_McalSpi;
      NvM_BlocksRom_McalWdg_Type          NvM_BlocksRom_McalWdg;
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
extern const NvM_BlocksRom_Type NvM_BlocksRom;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

