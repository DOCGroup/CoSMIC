// $Id$

#include "cuts/Benchmark_Agent.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Agent.inl"
#endif

#include "cuts/Benchmark_Visitor.h"
#include "cuts/Port_Agent.h"

//
// CUTS_Benchmark_Agent
//
CUTS_Benchmark_Agent::CUTS_Benchmark_Agent (void)
: parent_ (CUTS_UNKNOWN_IMPL)
{

}

//
// ~CUTS_Benchmark_Agent
//
CUTS_Benchmark_Agent::~CUTS_Benchmark_Agent (void)
{

}

//
// register_endpoint
//
int CUTS_Benchmark_Agent::
register_endpoint (const ACE_CString & endpoint,
                   size_t & endpoint_id)
{
  // Locate the <endpoint> in the <endpoints_> mapping.
  int retval = 0;
  Endpoint_Map::const_iterator iter = this->endpoints_.find (endpoint);

  if (iter == this->endpoints_.end ())
  {
    // Since we did not find it, we can create a new entry.
    endpoint_id = this->endpoints_.size ();
    this->endpoints_.insert (Endpoint_Map::value_type (endpoint, endpoint_id));
  }
  else
  {
    // Use the existing entry since it's already registered.
    endpoint_id = iter->second;
    retval = 1;
  }

  return retval;
}

//
// accept
//
void CUTS_Benchmark_Agent::accept (CUTS_Benchmark_Visitor & visitor)
{
  visitor.visit_benchmark_agent (*this);
}

//
// endpoint_name
//
const char * CUTS_Benchmark_Agent::endpoint_name (size_t id) const
{
  for (Endpoint_Map::const_iterator iter = this->endpoints_.begin ();
       iter != this->endpoints_.end ();
       iter ++)
  {
    if (iter->second == id)
      return iter->first.c_str ();
  }

  return 0;
}
