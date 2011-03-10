// $Id$

#include "stdafx.h"
#include "MetricsBase.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MetricsBase_Impl::metaname = "MetricsBase";

  //
  // MetricsBase_Impl
  //
  MetricsBase_Impl::MetricsBase_Impl (void)
  {
  }

  //
  // MetricsBase_Impl
  //
  MetricsBase_Impl::MetricsBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MetricsBase_Impl
  //
  MetricsBase_Impl::~MetricsBase_Impl (void)
  {
  }

  //
  // resolution
  //
  void MetricsBase_Impl::resolution (const std::string & val)
  {
    static const std::string attr_resolution ("resolution");
    this->attribute (attr_resolution)->string_value (val);
  }

  //
  // resolution
  //
  std::string MetricsBase_Impl::resolution (void) const
  {
    static const std::string attr_resolution ("resolution");
    return this->attribute (attr_resolution)->string_value ();
  }

  //
  // rate
  //
  void MetricsBase_Impl::rate (long val)
  {
    static const std::string attr_rate ("rate");
    this->attribute (attr_rate)->int_value (val);
  }

  //
  // rate
  //
  long MetricsBase_Impl::rate (void) const
  {
    static const std::string attr_rate ("rate");
    return this->attribute (attr_rate)->int_value ();
  }

  //
  // priority
  //
  void MetricsBase_Impl::priority (long val)
  {
    static const std::string attr_priority ("priority");
    this->attribute (attr_priority)->int_value (val);
  }

  //
  // priority
  //
  long MetricsBase_Impl::priority (void) const
  {
    static const std::string attr_priority ("priority");
    return this->attribute (attr_priority)->int_value ();
  }

  //
  // iterations
  //
  void MetricsBase_Impl::iterations (long val)
  {
    static const std::string attr_iterations ("iterations");
    this->attribute (attr_iterations)->int_value (val);
  }

  //
  // iterations
  //
  long MetricsBase_Impl::iterations (void) const
  {
    static const std::string attr_iterations ("iterations");
    return this->attribute (attr_iterations)->int_value ();
  }

  //
  // warmup
  //
  void MetricsBase_Impl::warmup (long val)
  {
    static const std::string attr_warmup ("warmup");
    this->attribute (attr_warmup)->int_value (val);
  }

  //
  // warmup
  //
  long MetricsBase_Impl::warmup (void) const
  {
    static const std::string attr_warmup ("warmup");
    return this->attribute (attr_warmup)->int_value ();
  }

  //
  // fileName
  //
  void MetricsBase_Impl::fileName (const std::string & val)
  {
    static const std::string attr_fileName ("fileName");
    this->attribute (attr_fileName)->string_value (val);
  }

  //
  // fileName
  //
  std::string MetricsBase_Impl::fileName (void) const
  {
    static const std::string attr_fileName ("fileName");
    return this->attribute (attr_fileName)->string_value ();
  }

  //
  // in_WorkloadCharacteristics_connections
  //
  size_t MetricsBase_Impl::in_WorkloadCharacteristics_connections (std::vector <WorkloadCharacteristics> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_BenchmarkCharacteristics_connections
  //
  size_t MetricsBase_Impl::in_BenchmarkCharacteristics_connections (std::vector <BenchmarkCharacteristics> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_MetricConnection_connections
  //
  size_t MetricsBase_Impl::in_MetricConnection_connections (std::vector <MetricConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // get_DataAnalysisBases
  //
  size_t MetricsBase_Impl::get_DataAnalysisBases (std::vector <DataAnalysisBase> & items) const
  {
    return this->children (items);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis MetricsBase_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

