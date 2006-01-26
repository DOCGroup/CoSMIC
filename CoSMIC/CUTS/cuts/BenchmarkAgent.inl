// $Id$

//
// register_port_agent
//
CUTS_INLINE
bool CUTS_Benchmark_Agent::register_port_agent (CUTS_Port_Agent * agent)
{
  return this->port_agents_.insert (agent).second;
}

//
// unregister_port_agent
//
CUTS_INLINE
void CUTS_Benchmark_Agent::unregister_port_agent (CUTS_Port_Agent * agent)
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
