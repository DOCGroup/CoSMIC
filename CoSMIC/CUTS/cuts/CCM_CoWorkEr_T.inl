// $Id$

//
// ciao_postactivate
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_T <COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::ciao_postactivate (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  COMPONENT_EXEC::ciao_postactivate ();
}

//
// ccm_passivate
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_T <COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::ccm_passivate (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  COMPONENT_EXEC::ccm_passivate ();
}

//
// ccm_remove
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_T <COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::ccm_remove (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  COMPONENT_EXEC::ccm_remove ();
}

//
// ccm_activate
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_T <COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::ccm_activate (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  COMPONENT_EXEC::ccm_activate ();
}

//
// set_session_context
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void
CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::set_session_context (
  ::Components::SessionContext_ptr ctx
  ACE_ENV_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  COMPONENT_EXEC::set_session_context (ctx);
}

//
// ciao_preactivate
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void
CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::ciao_preactivate (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException))
{
  COMPONENT_EXEC::ciao_preactivate ();
}

template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
::CUTS::CCM_Benchmark_Agent_ptr CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::get_benchmark_agent (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return CUTS::CCM_Benchmark_Agent::_duplicate (this->benchmark_agent_.get ());
}

//
// unique_id
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
::CORBA::Long CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::unique_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  return this->benchmark_agent_->parent ();
}

template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
void CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::unique_id (::CORBA::Long unique_id
                                                   ACE_ENV_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  this->benchmark_agent_->parent (unique_id);
}

