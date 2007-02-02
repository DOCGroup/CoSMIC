// $Id$

#include "CCM_Component_Registry.h"

namespace CUTS
{
  //
  // CCM_Component_Registry_Node
  //
  CCM_Component_Registry_Node::
  CCM_Component_Registry_Node (::CUTS::Benchmark_Agent_ptr agent)
  : agent_ (::CUTS::Benchmark_Agent::_duplicate (agent))
  {

  }

  //
  // ~CCM_Component_Registry_Node
  //
  CCM_Component_Registry_Node::~CCM_Component_Registry_Node (void)
  {

  }

  //
  // benchmark_agent
  //
  ::CUTS::Benchmark_Agent_ptr
    CCM_Component_Registry_Node::benchmark_agent (void)
  {
    return ::CUTS::Benchmark_Agent::_duplicate (this->agent_.in ());
  }
}
