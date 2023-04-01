#pragma once
/******************************************************************************/
/* File   : ServiceNvM.hpp                                                           */
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
#include "ConstServiceNvM.hpp"
#include "CfgServiceNvM.hpp"
#include "ServiceNvM_core.hpp"
#include "infServiceNvM_Exp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class module_ServiceNvM:
      INTERFACES_EXPORTED_SERVICENVM
      public abstract_module
   ,  public class_ServiceNvM_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
      const ConstServiceNvM_Type* lptrConst = (ConstServiceNvM_Type*)NULL_PTR;

   public:
/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
      FUNC(void, SERVICENVM_CODE) InitFunction(
            CONSTP2CONST(ConstModule_TypeAbstract, SERVICENVM_CONST,       SERVICENVM_APPL_CONST) lptrConstModule
         ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICENVM_CONFIG_DATA, SERVICENVM_APPL_CONST) lptrCfgModule
      );
      FUNC(void, SERVICENVM_CODE) DeInitFunction (void);
      FUNC(void, SERVICENVM_CODE) MainFunction   (void);
      SERVICENVM_CORE_FUNCTIONALITIES
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
extern VAR(module_ServiceNvM, SERVICENVM_VAR) ServiceNvM;

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

