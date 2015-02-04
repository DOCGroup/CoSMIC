// $Id$

#include "StdAfx.h"
#include "MetricConnection.h"

#if !defined (__GAME_INLINE__)
#include "MetricConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/Throughput.h"
#include "PICML/ComponentBenchmark/Latency.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MetricConnection_Impl::metaname ("MetricConnection");

  //
  // is_abstract
  //
  const bool MetricConnection_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in, OperationRef_in src, MetricsBase_in dst)
  //
  MetricConnection MetricConnection_Impl::_create (const BenchmarkAnalysis_in parent, OperationRef_in src, MetricsBase_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, MetricConnection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void MetricConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MetricConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis MetricConnection_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // OperationRef
  //
  OperationRef MetricConnection_Impl::src_OperationRef (void) const
  {
    return OperationRef::_narrow (this->src ());
  }

  //
  // MetricsBase
  //
  MetricsBase MetricConnection_Impl::dst_MetricsBase (void) const
  {
    return MetricsBase::_narrow (this->dst ());
  }
}

