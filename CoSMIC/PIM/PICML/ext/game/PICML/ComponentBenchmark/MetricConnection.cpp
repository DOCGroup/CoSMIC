// $Id$

#include "stdafx.h"
#include "MetricConnection.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MetricConnection_Impl::metaname = "MetricConnection";

  //
  // MetricConnection_Impl
  //
  MetricConnection_Impl::MetricConnection_Impl (void)
  {
  }

  //
  // MetricConnection_Impl
  //
  MetricConnection_Impl::MetricConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MetricConnection_Impl
  //
  MetricConnection_Impl::~MetricConnection_Impl (void)
  {
  }

  //
  // accept
  //
  void MetricConnection_Impl::accept (Visitor * v)
  {
    v->visit_MetricConnection (this);
  }

  //
  // _create
  //
  MetricConnection MetricConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <MetricConnection> (parent, MetricConnection_Impl::metaname);
  }

  //
  // src_OperationRef
  //
  OperationRef MetricConnection_Impl::src_OperationRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return OperationRef::_narrow (target);
  }

  //
  // dst_MetricsBase
  //
  MetricsBase MetricConnection_Impl::dst_MetricsBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return MetricsBase::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis MetricConnection_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

