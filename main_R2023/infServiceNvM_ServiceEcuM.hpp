#pragma once
/******************************************************************************/
/* File   : infServiceNvM_ServiceEcuM.hpp                                     */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
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
class NvM_BlocksNv_Type{
   public:
      NvM_BlocksNv_ApplSwcFoc_Type        NvM_BlocksNv_ApplSwcFoc;
      NvM_BlocksNv_ProjectARA_Type        NvM_BlocksNv_ProjectARA;
      NvM_BlocksNv_ServiceBswM_Type       NvM_BlocksNv_ServiceBswM;
      NvM_BlocksNv_ServiceCanNm_Type      NvM_BlocksNv_ServiceCanNm;
      NvM_BlocksNv_ServiceCanSm_Type      NvM_BlocksNv_ServiceCanSm;
      NvM_BlocksNv_ServiceCom_Type        NvM_BlocksNv_ServiceCom;
      NvM_BlocksNv_ServiceComM_Type       NvM_BlocksNv_ServiceComM;
      NvM_BlocksNv_ServiceCsm_Type        NvM_BlocksNv_ServiceCsm;
      NvM_BlocksNv_ServiceDcm_Type        NvM_BlocksNv_ServiceDcm;
      NvM_BlocksNv_ServiceDem_Type        NvM_BlocksNv_ServiceDem;
      NvM_BlocksNv_ServiceDet_Type        NvM_BlocksNv_ServiceDet;
      NvM_BlocksNv_ServiceDlt_Type        NvM_BlocksNv_ServiceDlt;
      NvM_BlocksNv_ServiceEcuM_Type       NvM_BlocksNv_ServiceEcuM;
      NvM_BlocksNv_ServiceFiM_Type        NvM_BlocksNv_ServiceFiM;
      NvM_BlocksNv_ServiceFrNm_Type       NvM_BlocksNv_ServiceFrNm;
      NvM_BlocksNv_ServiceIpduM_Type      NvM_BlocksNv_ServiceIpduM;
      NvM_BlocksNv_ServiceNm_Type         NvM_BlocksNv_ServiceNm;
      NvM_BlocksNv_ServiceNvM_Type        NvM_BlocksNv_ServiceNvM;
      NvM_BlocksNv_ServiceOs_Type         NvM_BlocksNv_ServiceOs;
      NvM_BlocksNv_ServicePduR_Type       NvM_BlocksNv_ServicePduR;
      NvM_BlocksNv_ServiceSchM_Type       NvM_BlocksNv_ServiceSchM;
      NvM_BlocksNv_ServiceSecOC_Type      NvM_BlocksNv_ServiceSecOC;
      NvM_BlocksNv_ServiceSokFm_Type      NvM_BlocksNv_ServiceSokFm;
      NvM_BlocksNv_ServiceStartUp_Type    NvM_BlocksNv_ServiceStartUp;
      NvM_BlocksNv_ServiceStbM_Type       NvM_BlocksNv_ServiceStbM;
      NvM_BlocksNv_ServiceSwcEcuM_Type    NvM_BlocksNv_ServiceSwcEcuM;
      NvM_BlocksNv_ServiceSwcOs_Type      NvM_BlocksNv_ServiceSwcOs;
      NvM_BlocksNv_ServiceVkms_Type       NvM_BlocksNv_ServiceVkms;
      NvM_BlocksNv_ServiceWdgM_Type       NvM_BlocksNv_ServiceWdgM;
      NvM_BlocksNv_EcuabCanIf_Type        NvM_BlocksNv_EcuabCanIf;
      NvM_BlocksNv_EcuabCanTp_Type        NvM_BlocksNv_EcuabCanTp;
      NvM_BlocksNv_EcuabCryIf_Type        NvM_BlocksNv_EcuabCryIf;
      NvM_BlocksNv_EcuabEa_Type           NvM_BlocksNv_EcuabEa;
      NvM_BlocksNv_EcuabEthIf_Type        NvM_BlocksNv_EcuabEthIf;
      NvM_BlocksNv_EcuabFee_Type          NvM_BlocksNv_EcuabFee;
      NvM_BlocksNv_EcuabFrIf_Type         NvM_BlocksNv_EcuabFrIf;
      NvM_BlocksNv_EcuabFrTp_Type         NvM_BlocksNv_EcuabFrTp;
      NvM_BlocksNv_EcuabJ1939Tp_Type      NvM_BlocksNv_EcuabJ1939Tp;
      NvM_BlocksNv_EcuabLinIf_Type        NvM_BlocksNv_EcuabLinIf;
      NvM_BlocksNv_EcuabLinTp_Type        NvM_BlocksNv_EcuabLinTp;
      NvM_BlocksNv_EcuabMemIf_Type        NvM_BlocksNv_EcuabMemIf;
      NvM_BlocksNv_EcuabWdgIf_Type        NvM_BlocksNv_EcuabWdgIf;
      NvM_BlocksNv_McalAdc_Type           NvM_BlocksNv_McalAdc;
      NvM_BlocksNv_McalCan_Type           NvM_BlocksNv_McalCan;
      NvM_BlocksNv_McalCry_Type           NvM_BlocksNv_McalCry;
      NvM_BlocksNv_McalDio_Type           NvM_BlocksNv_McalDio;
      NvM_BlocksNv_McalEep_Type           NvM_BlocksNv_McalEep;
      NvM_BlocksNv_McalEth_Type           NvM_BlocksNv_McalEth;
      NvM_BlocksNv_McalFls_Type           NvM_BlocksNv_McalFls;
      NvM_BlocksNv_McalFr_Type            NvM_BlocksNv_McalFr;
      NvM_BlocksNv_McalGpt_Type           NvM_BlocksNv_McalGpt;
      NvM_BlocksNv_McalIcu_Type           NvM_BlocksNv_McalIcu;
      NvM_BlocksNv_McalLin_Type           NvM_BlocksNv_McalLin;
      NvM_BlocksNv_McalMcu_Type           NvM_BlocksNv_McalMcu;
      NvM_BlocksNv_McalOcu_Type           NvM_BlocksNv_McalOcu;
      NvM_BlocksNv_McalPort_Type          NvM_BlocksNv_McalPort;
      NvM_BlocksNv_McalPwm_Type           NvM_BlocksNv_McalPwm;
      NvM_BlocksNv_McalSpi_Type           NvM_BlocksNv_McalSpi;
      NvM_BlocksNv_McalWdg_Type           NvM_BlocksNv_McalWdg;
};

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

