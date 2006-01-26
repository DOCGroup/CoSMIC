// $Id$

template <typename BENCHMARK_AGENT_EXEC>
CUTS_INLINE
::CUTS::Benchmark_Data * CUTS_CCM_Benchmark_Agent_T
<BENCHMARK_AGENT_EXEC>::performance_data (
  ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  ACE_THROW_SPEC ((::CORBA::SystemException))
{
  return CUTS_CCM_Benchmark_Agent::performance_data ();
}
