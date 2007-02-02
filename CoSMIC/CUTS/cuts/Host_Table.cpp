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
                           const ACE_CString & hostname,
                           const CUTS_Host_Table_Entry ** entry)
{
  // Determine if we have already bound an ip-address
  // or hostname using either parameter.
  CUTS_Host_Table_Entry * temp = 0;
  int result = this->ipaddr_index_.find (ipaddr, temp);

  if (result == 0)
  {
    if (entry != 0)
      *entry = temp;
    return 1;
  }

  // Create a new temp for the host table.
  ACE_NEW_RETURN (temp, CUTS_Host_Table_Entry, -1);

  if (this->entries_.insert (temp) == 0)
  {
    temp->ipaddr_ = ipaddr;
    temp->hostname_ = hostname;

    // Update the index table(s) for fast access.
    this->ipaddr_index_.bind (ipaddr, temp);
    this->host_index_.bind (hostname, temp);

    if (entry != 0)
      *entry = temp;
  }
  else
  {
    // Delete the temp since we could not insert it
    // into the <entries_> table.
    delete temp;
    temp = 0;
  }

  return temp != 0 ? 0 : -1;
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
