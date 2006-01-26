// $Id$

#if !defined (__CUTS_INLINE__)
# include "cuts/CCM_CoWorkEr_T.inl"
#endif

//
// CUTS_CCM_CoWorkEr_T
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::CUTS_CCM_CoWorkEr_T (void)
: benchmark_agent_ (new This_Benchmark_Agent)
{

}

//
// ~CUTS_CCM_CoWorkEr_T
//
template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
CUTS_CCM_CoWorkEr_T
<COMPONENT_EXEC, BENCHMARK_AGENT_EXEC>::~CUTS_CCM_CoWorkEr_T (void)
{

}
