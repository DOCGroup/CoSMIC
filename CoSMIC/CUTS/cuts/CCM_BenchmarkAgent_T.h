#ifndef _CUTS_CCM_BENCHMARK_AGENT_T_H_
#define _CUTS_CCM_BENCHMARK_AGENT_T_H_

#include "cuts/CCM_BenchmarkAgent.h"

template <typename BENCHMARK_AGENT_EXEC>
class CUTS_CCM_Benchmark_Agent_T :
 virtual public CUTS_CCM_Benchmark_Agent,
 virtual public BENCHMARK_AGENT_EXEC
{
public:
  CUTS_CCM_Benchmark_Agent_T (void);

  virtual ~CUTS_CCM_Benchmark_Agent_T (void);

  virtual ::CUTS::Benchmark_Data *  performance_data (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException));
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_BenchmarkAgent_T.inl"
#endif

#include "cuts/CCM_BenchmarkAgent_T.cpp"

#endif  // !defined _CUTS_CCM_BENCHMARK_AGENT_T_H_
