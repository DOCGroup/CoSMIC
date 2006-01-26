// -*- C++ -*-

//=============================================================================
/**
 *
 */
//=============================================================================

#ifndef _CUTS_BENCHMARK_AGENT_T_H_
#define _CUTS_BENCHMARK_AGENT_T_H_

#include "cuts/config.h"
#include "cuts/CUTS_exec_export.h"
#include "cuts/CUTSC.h"
#include "cuts/BenchmarkAgent.h"

//=============================================================================
/**
 *
 */
//=============================================================================

class CUTS_EXEC_Export CUTS_CCM_Benchmark_Agent :
  public CUTS_Benchmark_Agent
{
public:
  /// Constructor.
  CUTS_CCM_Benchmark_Agent (void);

  /// Destructor.
  virtual ~CUTS_CCM_Benchmark_Agent (void);

  /// Get the performance data from the Benchmark_Agent
  virtual ::CUTS::Benchmark_Data *  performance_data (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException));
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_BenchmarkAgent.inl"
#endif

#endif  // !defined _CUTS_BENCHMARK_AGENT_T_H_
