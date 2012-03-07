// $Id$

#include "StdAfx.h"
#include "MetricsBase.h"

#if !defined (__GAME_INLINE__)
#include "MetricsBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MetricsBase_Impl::metaname ("MetricsBase");

  //
  // src_WorkloadCharacteristics
  //
  size_t MetricsBase_Impl::src_WorkloadCharacteristics (std::vector <WorkloadCharacteristics> & items) const
  {
    return this->in_connections <WorkloadCharacteristics> (items);
  }

  //
  // dst_MetricConnection
  //
  size_t MetricsBase_Impl::dst_MetricConnection (std::vector <MetricConnection> & items) const
  {
    return this->in_connections <MetricConnection> (items);
  }

  //
  // dst_BenchmarkCharacteristics
  //
  size_t MetricsBase_Impl::dst_BenchmarkCharacteristics (std::vector <BenchmarkCharacteristics> & items) const
  {
    return this->in_connections <BenchmarkCharacteristics> (items);
  }

  //
  // get_DataAnalysisBases
  //
  size_t MetricsBase_Impl::get_DataAnalysisBases (std::vector <DataAnalysisBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataAnalysisBases
  //
  ::GAME::Mga::Iterator <DataAnalysisBase> MetricsBase_Impl::get_DataAnalysisBases (void) const
  {
    return this->children <DataAnalysisBase> ();
  }
}

