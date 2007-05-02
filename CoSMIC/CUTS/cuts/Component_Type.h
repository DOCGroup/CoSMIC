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
#include "ace/SString.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

typedef
  ACE_Hash_Map_Manager <
  size_t, ACE_CString, ACE_Null_Mutex>
  CUTS_Port_Description_Map;

struct CUTS_Component_Type
{
  ACE_CString name_;

  CUTS_Port_Description_Map sources_;

  CUTS_Port_Description_Map sinks_;
};

#endif  // !defined _CUTS_COMPONENT_TYPE_H_
