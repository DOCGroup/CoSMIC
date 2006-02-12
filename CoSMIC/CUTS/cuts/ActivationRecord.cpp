// $Id$

#include "cuts/ActivationRecord.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/ActivationRecord.inl"
#include "ace/OS_NS_sys_time.h"
#endif

//=============================================================================
/*
 * CUTS_Activation_Record
 */
//=============================================================================

//
// CUTS_Activation_Record
//
CUTS_Activation_Record::CUTS_Activation_Record (void)
: active_ (false)
{

}

//
// ~CUTS_Activation_Record
//
CUTS_Activation_Record::~CUTS_Activation_Record (void)
{

}

//=============================================================================
/*
 * CUTS_Cached_Activation_Record
 */
//=============================================================================

CUTS_Cached_Activation_Record::CUTS_Cached_Activation_Record (void)
: next_ (0)
{

}

CUTS_Cached_Activation_Record::~CUTS_Cached_Activation_Record (void)
{

}

