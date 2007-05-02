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
// register_endpoint
//
CUTS_INLINE
int CUTS_Benchmark_Agent::
register_endpoint (const ACE_CString & endpoint, size_t endpoint_id)
{
  this->endpoints_[endpoint] = endpoint_id;
  return 0;
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

CUTS_INLINE
const CUTS_Benchmark_Agent::Endpoint_Map &
CUTS_Benchmark_Agent::endpoints (void) const
{
  return this->endpoints_;
}
