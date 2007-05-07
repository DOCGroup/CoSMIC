// $Id$

#include "CUTS_i.h"
#include "cuts/Port_Agent.h"

//=============================================================================
// @@ extraction operations

//
// operator >>=
//
void operator >>= (const CUTS::Port_Descriptions & desc,
                   CUTS_Port_Description_Map & map)
{
  CORBA::ULong curr_size = desc.length ();
  CUTS::Port_Descriptions::const_value_type * buf = desc.get_buffer ();
  CUTS::Port_Descriptions::const_value_type * buf_stop = buf + curr_size;

  for (; buf != buf_stop; buf ++)
    map.bind (buf->uid, buf->name.in ());
}

//=============================================================================
// @@ insertion operations

void operator <<= (CUTS::Port_Descriptions & desc,
                   const CUTS_Port_Agent_Set & agents)
{
  // Initialize the size of the source port descriptions.
  desc.length (agents.current_size ());

  // Get an iterator/pointer to the elements in both collections.
  CUTS_Port_Agent_Set::CONST_ITERATOR iter (agents);
  CUTS::Port_Descriptions::value_type * buf = desc.get_buffer ();

  CUTS_Port_Agent * agent = 0;

  for (; !iter.done (); iter ++)
  {
    // Get the port agent.
    agent = reinterpret_cast <CUTS_Port_Agent *> (iter->key ());

    // Store the information about the port.
    buf->name = CORBA::string_dup (agent->name ().c_str ());
    buf->uid = iter->item ();

    // Move to the next slot in the buffer.
    buf ++;
  }
}

//
// operator <<=
//
void operator <<= (CUTS::Port_Descriptions & desc,
                   const CUTS_Endpoint_Map & ends)
{
  // Set the size of the description buffer.
  desc.length (ends.current_size ());

  // Get iterator/pointer to the source/destination buffer.
  CUTS_Endpoint_Map::CONST_ITERATOR iter (ends);
  CUTS::Port_Descriptions::value_type * buf = desc.get_buffer ();

  for (; !iter.done (); iter ++)
  {
    buf->name = CORBA::string_dup (iter->key ().c_str ());
    buf->uid = iter->item ();

    // Goto the next slot in the buffer.
    buf ++;
  }
}
