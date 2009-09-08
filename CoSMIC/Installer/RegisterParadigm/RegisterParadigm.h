// -*- C++ -*-

//=============================================================================
/**
 * @file        RegisterParadigm.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _COSMIC_REGISTER_PARADIGM_H_
#define _COSMIC_REGISTER_PARADIGM_H_

#include "CoSMIC_Msi_export.h"

#if defined (__cplusplus)
extern "C" {
#endif

COSMIC_MSI_Export UINT RegisterParadigms (MSIHANDLE);

COSMIC_MSI_Export UINT UnregisterParadigms (MSIHANDLE);

COSMIC_MSI_Export UINT CheckGMEVersion_6_11_9 (MSIHANDLE);

COSMIC_MSI_Export UINT CheckGMEVersion_7_6_29 (MSIHANDLE);

COSMIC_MSI_Export UINT CheckGMEVersion_9_8_28 (MSIHANDLE);

#if defined (__cplusplus)
}
#endif

#endif
