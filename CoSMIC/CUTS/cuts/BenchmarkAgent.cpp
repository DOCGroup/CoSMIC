// $Id

#include "cuts/BenchmarkAgent.h"

#if !defined (__CUTS_INLINE__)
# include "cuts/BenchmarkAgent.inl"
#endif  // !defined __CUTS_INLINE__

#include "cuts/PortAgent.h"

//
// CUTS_Benchmark_Agent
//
CUTS_Benchmark_Agent::CUTS_Benchmark_Agent (void)
: parent_ (-1)
{

}

//
// ~CUTS_Benchmark_Agent
//
CUTS_Benchmark_Agent::~CUTS_Benchmark_Agent (void)
{
  for ( Port_Agents::iterator iter = this->port_agents_.begin ();
        iter != this->port_agents_.end ();
        iter ++)
  {
    delete (*iter);
  }
}
