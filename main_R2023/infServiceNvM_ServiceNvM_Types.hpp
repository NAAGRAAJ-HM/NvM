#pragma once
/******************************************************************************/
/* File   : infServiceNvM_ServiceNvM_Types.hpp                                */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infEcuabMemIf_ServiceNvM.hpp"

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class NvM_BlocksRom_ServiceNvM_Type:
      public ConstModule_TypeAbstract
{
   public:
      infEcuabMemIf_ServiceNvM* ptrinfEcuabMemIf_ServiceNvM;
};

class NvM_BlocksNv_ServiceNvM_Type:
      public CfgModule_TypeAbstract
{
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

