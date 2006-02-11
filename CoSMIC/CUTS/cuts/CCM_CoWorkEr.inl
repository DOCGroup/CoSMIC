// $Id$

//
// server_name
//
CUTS_INLINE
void CUTS_CCM_CoWorkEr::cuts_coworker_database (const char * database)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->server_name_ = database;
}

//
// get_cuts_benchmark_agent
//
CUTS_INLINE
::CUTS::CCM_Benchmark_Agent_ptr
CUTS_CCM_CoWorkEr::get_cuts_benchmark_agent (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException))
{
  return ::CUTS::CCM_Benchmark_Agent::_duplicate (
    this->benchmark_agent_.get ());
}

//
// cuts_coworker_id
//
CUTS_INLINE
void CUTS_CCM_CoWorkEr::cuts_coworker_id (const char * parent
                                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->benchmark_agent_->parent (parent);
}
