// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Type.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COMPONENT_TYPE_H_
#define _CUTS_COMPONENT_TYPE_H_

#include "cuts/CUTS_export.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

/// Type definition for the port description.
typedef
  ACE_Hash_Map_Manager <
  size_t, ACE_CString, ACE_Null_Mutex>
  CUTS_Port_Description_Map;

//=============================================================================
/**
 * @struct CUTS_Component_Type
 *
 * Contains information about a components type. The type information
 * includes its typename and the names of its ports.
 */
//=============================================================================

struct CUTS_Component_Type
{
  /// The type name of the component.
  ACE_CString name_;

  /// Collection of source for the component.
  CUTS_Port_Description_Map sources_;

  /// Collection of sinks for the component.
  CUTS_Port_Description_Map sinks_;
};

#endif  // !defined _CUTS_COMPONENT_TYPE_H_
