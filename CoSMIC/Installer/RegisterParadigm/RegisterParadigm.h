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

COSMIC_MSI_Export UINT CheckGMEVersion (MSIHANDLE);

#if defined (__cplusplus)
}
#endif

#endif
