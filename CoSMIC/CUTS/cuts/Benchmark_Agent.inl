// $Id$

//
// CUTS_Benchmark_Agent
//
CUTS_INLINE
CUTS_Benchmark_Agent::CUTS_Benchmark_Agent (void)
: parent_ (CUTS_UNKNOWN_IMPL)
{

}

//
// ~CUTS_Benchmark_Agent
//
CUTS_INLINE
CUTS_Benchmark_Agent::~CUTS_Benchmark_Agent (void)
{

}

//
// register_agent
//
CUTS_INLINE
int CUTS_Benchmark_Agent::
register_agent (CUTS_Port_Agent * agent, size_t agent_id)
{
  return this->port_agents_.bind (agent, agent_id);
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

//
// endpoints
//
CUTS_INLINE
const CUTS_Endpoint_Map & CUTS_Benchmark_Agent::endpoints (void) const
{
  return this->endpoints_;
}

//
// endpoints
//
CUTS_INLINE
CUTS_Endpoint_Map & CUTS_Benchmark_Agent::endpoints (void)
{
  return this->endpoints_;
}
