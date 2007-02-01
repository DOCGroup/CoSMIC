// $Id$

#include "cuts/Host_Table.h"
#include "cuts/Host_Table_Entry.h"
#include "ace/String_Base.h"

//
// CUTS_Host_Table
//
CUTS_Host_Table::CUTS_Host_Table (void)
{

}

//
// ~CUTS_Host_Table
//
CUTS_Host_Table::~CUTS_Host_Table (void)
{
  Entry_Table::ITERATOR iter (this->entries_);

  while (!iter.done ())
  {
    iter.advance ();
  }
}

//
// bind
//
int CUTS_Host_Table::bind (const ACE_CString & ipaddr,
                           const ACE_CString & hostname)
{
  // Determine if we have already bound an ip-address
  // or hostname using either parameter.
  int result_1 = this->ipaddr_index_.find (ipaddr);
  int result_2 = this->host_index_.find (hostname);

  if (result_1 == 0 || result_2 == 0)
    return 1;

  // Create a new entry for the host table.
  CUTS_Host_Table_Entry * entry = 0;
  ACE_NEW_RETURN (entry, CUTS_Host_Table_Entry, -1);

  entry->ipaddr_ = ipaddr;
  entry->hostname_ = hostname;

  // Update the index table(s) for fast access.
  this->ipaddr_index_.bind (ipaddr, entry);
  this->host_index_.bind (hostname, entry);
  return 0;
}

//
// find
//
int CUTS_Host_Table::find_by_name (const ACE_CString & hostname,
                                   const CUTS_Host_Table_Entry * entry)
{
  CUTS_Host_Table_Entry * temp = 0;
  int retval = this->host_index_.find (hostname, temp);

  if (retval == 0)
    entry = temp;

  return retval;
}

//
// find
//
int CUTS_Host_Table::find_by_addr (const ACE_CString & ipaddr,
                                   const CUTS_Host_Table_Entry * entry)
{
  CUTS_Host_Table_Entry * temp = 0;
  int retval = this->ipaddr_index_.find (ipaddr, temp);

  if (retval == 0)
    entry = temp;

  return retval;
}

//
// unbind
//
void CUTS_Host_Table::unbind_by_ipaddr (const ACE_CString & ipaddr)
{
  // Locate the <ipaddr> in the map.
  Ipaddr_Index::ENTRY * entry = 0;
  int result = this->ipaddr_index_.find (ipaddr, entry);

  if (result == 0 && entry != 0)
  {
    // Remove the entry for the <host_index_>.
    this->host_index_.unbind (entry->int_id_->hostname_);

    // Delete the entry from the <entries_> table.
    this->entries_.remove (entry->int_id_);
    delete entry->int_id_;

    // Remove the entry from <ipaddr_index_>.
    this->ipaddr_index_.unbind (entry);
  }
}

//
// unbind
//
void CUTS_Host_Table::unbind_by_name (const ACE_CString & hostname)
{
  // Locate the <hostname> in the map.
  Hostname_Index::ENTRY * entry = 0;
  int result = this->host_index_.find (hostname, entry);

  if (result == 0 && entry != 0)
  {
    // Remove the entry for the <ipaddr_index_>.
    this->ipaddr_index_.unbind (entry->int_id_->ipaddr_);

    // Delete the entry from the <entries_> table.
    this->entries_.remove (entry->int_id_);
    delete entry->int_id_;

    // Remove the entry from <ipaddr_index_>.
    this->host_index_.unbind (entry);
  }
}
