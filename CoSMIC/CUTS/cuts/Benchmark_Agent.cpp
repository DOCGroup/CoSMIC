// $Id$

#include "cuts/Benchmark_Agent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Agent.inl"
#endif

#include "cuts/Port_Agent.h"

//
// register_endpoint
//
int CUTS_Benchmark_Agent::
register_endpoint (const ACE_CString & endpoint, size_t endpoint_id)
{
  int retval = this->endpoints_.bind (endpoint, endpoint_id);
  CUTS_Port_Agent * agent;

  if (retval == 0)
  {
    CUTS_Port_Agent_Set::ITERATOR iter (this->port_agents ());

    for (; !iter.done (); iter ++)
    {
      agent = reinterpret_cast <CUTS_Port_Agent *> (iter->key ());
      agent->sender_map ().register_endpoint (endpoint_id);
    }    
  }

  return retval;
}

