#ifndef __WRAPNV_H__
#define __WRAPNV_H__

#define SYSSERVICE_WRAPPERNV_VERSION              0x0206u
#define SYSSERVICE_WRAPPERNV_RELEASE_VERSION      0x02u

#include "CfgSwcServiceNvM.hpp"

#if defined( kFblOk )
#define WRAPNV_E_OK                kFblOk
#elif defined( kEepMgrOk )
#define WRAPNV_E_OK                kEepMgrOk
#elif defined( E_OK )
#define WRAPNV_E_OK                E_OK
#else
#define WRAPNV_E_OK                0u
#endif

#if defined( kFblFailed )
#define WRAPNV_E_NOT_OK            kFblFailed
#elif defined( kEepMgrFailed )
#define WRAPNV_E_NOT_OK            kEepMgrFailed
#elif defined( E_NOT_OK )
#define WRAPNV_E_NOT_OK            E_NOT_OK
#else
#define WRAPNV_E_NOT_OK            1u
#endif

#if defined( kEepMgrBusy )
#define WRAPNV_E_PENDING           kEepMgrBusy
#elif defined( E_PENDING )
#define WRAPNV_E_PENDING           E_PENDING
#else
#define WRAPNV_E_PENDING           2u
#endif

#if defined( kFblOk )
#define WrapNv_ReturnType          tFblResult
#elif defined( kEepMgrOk )
#define WrapNv_ReturnType          vuint8
#elif defined( E_OK )
#define WrapNv_ReturnType          Std_ReturnType
#else
#define WrapNv_ReturnType          WrapNv_DefaultReturntype
#endif

typedef enum{
   WRAPNV_OPSTATUS_INIT = 0u
   ,  WRAPNV_OPSTATUS_PENDING
   ,  WRAPNV_OPSTATUS_CANCEL
   ,  WRAPNV_OPSTATUS_IDLE
}tWrapNvOpStatus;

typedef unsigned char WrapNv_DefaultReturntype;

#if defined( WRAPNV_USECASE_DRVEEP )
#include "fbl_def.hpp"
#include "fbl_inc.hpp"
#include "iotypes.hpp"
#include "EepInc.hpp"
#include "EepIO.hpp"
#endif

#endif

