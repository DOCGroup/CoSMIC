// -*- C++ -*-

//=============================================================================
/**
 * @file      Benchmark_Collector_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BENCHMARK_COLLECTOR_VISITOR_H_
#define _CUTS_BENCHMARK_COLLECTOR_VISITOR_H_

#include "cuts/Benchmark_Visitor.h"
#include "cuts/performanceC.h"

class CUTS_Benchmark_Collector_Visitor : public CUTS_Benchmark_Visitor
{
public:
  CUTS_Benchmark_Collector_Visitor (::CUTS::Benchmark_Data & data);

  ~CUTS_Benchmark_Collector_Visitor (void);

  void visit_benchmark_agent (const CUTS_Benchmark_Agent & agent);

  void visit_port_agent (const CUTS_Port_Agent & agent);

  void visit_port_measurement (const CUTS_Port_Measurement & measurement);

private:
  /// Target data object for metrics.
  ::CUTS::Benchmark_Data & data_;

  /// The current port agent.
  const CUTS_Benchmark_Agent * agent_;

  /// The current port measurement.
  ::CUTS::Port_Measurement * active_pm_;

  ::CUTS::Mapped_Port_Measurement * active_mpm_;
};

#endif  // !defined _CUTS_BENCHMARK_COLLECTOR_VISITOR_H_
