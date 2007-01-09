// $Id$

//
// register_agent
//
CUTS_INLINE
bool CUTS_Benchmark_Agent::register_agent (CUTS_Port_Agent * agent)
{
  return this->port_agents_.insert (agent).second;
}

//
// unregister_agent
//
CUTS_INLINE
void CUTS_Benchmark_Agent::unregister_agent (CUTS_Port_Agent * agent)
{
  this->port_agents_.erase (agent);
}

//
// parent
//
CUTS_INLINE
void CUTS_Benchmark_Agent::parent (long parent)
{
  this->parent_ = parent;
}

CUTS_INLINE
long CUTS_Benchmark_Agent::parent (void) const
{
  return this->parent_;
}

//
// port_agents
//
CUTS_INLINE
CUTS_Port_Agent_Set & CUTS_Benchmark_Agent::port_agents (void)
{
  return this->port_agents_;
}

//
// port_agents
//
CUTS_INLINE
const CUTS_Port_Agent_Set & CUTS_Benchmark_Agent::port_agents (void) const
{
  return this->port_agents_;
}
