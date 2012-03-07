// $Id$

#include "StdAfx.h"
#include "MetricConnection.h"

#if !defined (__GAME_INLINE__)
#include "MetricConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
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
  // _create (const BenchmarkAnalysis_in)
  //
  MetricConnection MetricConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < MetricConnection > (parent, MetricConnection_Impl::metaname);
  }

  //
  // accept
  //
  void MetricConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_MetricConnection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

