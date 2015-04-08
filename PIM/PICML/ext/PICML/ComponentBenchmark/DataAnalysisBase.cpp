#include "StdAfx.h"
#include "DataAnalysisBase.h"

#if !defined (__GAME_INLINE__)
#include "DataAnalysisBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/Throughput.h"
#include "PICML/ComponentBenchmark/Latency.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataAnalysisBase_Impl::metaname ("DataAnalysisBase");

  //
  // is_abstract
  //
  const bool DataAnalysisBase_Impl::is_abstract = true;

  //
  // parent_MetricsBase
  //
  MetricsBase DataAnalysisBase_Impl::parent_MetricsBase (void)
  {
    return MetricsBase::_narrow (this->parent ());
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis DataAnalysisBase_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }
}

