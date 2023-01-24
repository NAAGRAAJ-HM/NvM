#pragma once
/******************************************************************************/
/* File   : infServiceNvM_ServiceNvM.hpp                                      */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infEcuabMemIf_ServiceNvM.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CONSTSERVICENVM_AR_RELEASE_VERSION_MAJOR                               4
#define CONSTSERVICENVM_AR_RELEASE_VERSION_MINOR                               3

#define Const_DefaultInit_ConstServiceNvM                                                                                    \
   ,  {                                                                                                                      \
            {CONSTSERVICENVM_AR_RELEASE_VERSION_MAJOR, CONSTSERVICENVM_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'} \
         ,  &EcuabMemIf                                                                                                      \
      }                                                                                                                      \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CONSTSERVICENVM_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CONSTSERVICENVM_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CONSTSERVICENVM_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CONSTSERVICENVM_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

