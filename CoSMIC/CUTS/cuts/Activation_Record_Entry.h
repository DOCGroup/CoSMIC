// -*- C++ -*-

//=============================================================================
/**
 * @file      Activation_Record_Entry.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ACTIVATION_RECORD_ENTRY_H_
#define _CUTS_ACTIVATION_RECORD_ENTRY_H_

#include "cuts/CUTS_export.h"
#include "ace/Time_Value.h"

//=============================================================================
/**
 * @class CUTS_Activation_Record_Entry
 *
 * Entries for actions in the activation record.
 */
//=============================================================================

struct CUTS_Export CUTS_Activation_Record_Entry
{
  /// Unique id for the entry.
  size_t uid_;

  /// Type of action
  size_t type_;

  /// Measured duration of the action.
  ACE_Time_Value duration_;
};

#endif  // !defined _CUTS_ACTIVATION_RECORD_ENTRY_H_
