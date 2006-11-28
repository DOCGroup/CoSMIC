// $Id$

#include "cuts/Testing_Service.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Testing_Service.inl"
#endif

#include "cuts/Component_Registry.h"

//
// CUTS_Testing_Service
//
CUTS_Testing_Service::
CUTS_Testing_Service (CUTS_Component_Registry * registry)
: registry_ (registry)
{

}

//
// ~CUTS_Testing_Service
//
CUTS_Testing_Service::~CUTS_Testing_Service (void)
{

}
