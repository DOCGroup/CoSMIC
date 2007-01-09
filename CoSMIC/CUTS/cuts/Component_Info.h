// -*- C++ -*-

#ifndef _CUTS_COMPONENT_INFO_H_
#define _CUTS_COMPONENT_INFO_H_

#include "cuts/CUTS_export.h"
#include "ace/SString.h"

struct CUTS_Export CUTS_Component_Info
{
  /// Unique id for the component.
  size_t uid_;

  /// The state of the component.
  int state_;

  /// Instance id for the component.
  ACE_CString inst_;

  /// Component type id.
  ACE_CString type_;
};

#endif  // !defined _CUTS_COMPONENT_INFO_H_
