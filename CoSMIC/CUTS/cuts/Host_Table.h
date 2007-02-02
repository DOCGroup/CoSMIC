// -*- C++ -*-

//=============================================================================
/**
 * @file      Host_Table.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_HOST_TABLE_H_
#define _CUTS_HOST_TABLE_H_

#include "cuts/CUTS_export.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Unbounded_Set.h"
#include "ace/SString.h"

// Forward decl.
class ACE_RW_Thread_Mutex;

// Forward decl.
class CUTS_Host_Table_Entry;

//=============================================================================
/**
 * @class CUTS_Host_Table
 *
 * Mapping of IP-addresses to names of hosts.
 */
//=============================================================================

class CUTS_Export CUTS_Host_Table
{
public:
  /// Default constructor.
  CUTS_Host_Table (void);

  /// Destructor.
  ~CUTS_Host_Table (void);

  /**
   * Bind the IP-address to the specified hostname.
   *
   * @param[in]     ipaddr            IP-address.
   * @param[in]     hostname          Name of the host.
   * @param[out]    entry             The table entry.
   * @retval        >0                Succeeded
   * @retval        -1                Failed
   */
  int bind (const ACE_CString & ipaddr,
            const ACE_CString & hostname,
            const CUTS_Host_Table_Entry ** entry = 0);

  /**
   * Remove an entry by using its hostname.
   *
   * @param[in]     hostname    Target hostname.
   */
  void unbind_by_ipaddr (const ACE_CString & ipaddr);

  /**
   * Remove an entry by using its IP-address.
   *
   * @param[in]     ipaddr      Target IP-address.
   */
  void unbind_by_name (const ACE_CString & ipaddr);

  /**
   * Find the hostname given an IP-address.
   *
   * @retval      -1      The hostname was not found.
   */
  int find_by_addr (const ACE_CString & ipaddr,
                    const CUTS_Host_Table_Entry * entry);

  /**
   * Find the IP-address given a hostname.
   *
   * @retval      -1      The hostname was not found.
   */
  int find_by_name (const ACE_CString & hostname,
                    const CUTS_Host_Table_Entry * entry);

private:
  /// Type definition of an IP-address map.
  typedef ACE_Hash_Map_Manager <ACE_CString,
                                CUTS_Host_Table_Entry *,
                                ACE_RW_Thread_Mutex> Ipaddr_Index;

  /// Type defintion of a hostname map.
  typedef ACE_Hash_Map_Manager <ACE_CString,
                                CUTS_Host_Table_Entry *,
                                ACE_RW_Thread_Mutex> Hostname_Index;

  /// Type defintion of the entry list.
  typedef ACE_Unbounded_Set <CUTS_Host_Table_Entry *> Entry_Table;

  /// Collection of registered ipaddr->hosts pairs.
  Entry_Table entries_;

  /// Mapping of IP-address to hostname.
  Ipaddr_Index ipaddr_index_;

  /// Mapping of hostname to IP-address.
  Hostname_Index host_index_;
};

#endif  // !defined _CUTS_HOST_TABLE_H_
