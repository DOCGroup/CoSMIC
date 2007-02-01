// -*- C++ -*-

//=============================================================================
/**
 * @file      Host_Table_Entry.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_HOST_TABLE_ENTRY_H_
#define _CUTS_HOST_TABLE_ENTRY_H_

#include "cuts/CUTS_export.h"
#include "ace/SString.h"

//=============================================================================
/**
 * @class CUTS_Host_Table_Entry
 *
 * Entry for the CUTS_Host_Table.
 */
//=============================================================================

class CUTS_Export CUTS_Host_Table_Entry
{
public:
  /// IP-address of the host.
  ACE_CString ipaddr_;

  /// DNS address of the host.
  ACE_CString hostname_;
};

#endif  // !defined _CUTS_HOST_TABLE_ENTRY_H_
