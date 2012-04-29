// $Id$

#include "StdAfx.h"
#include "Latency.h"

#if !defined (__GAME_INLINE__)
#include "Latency.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Latency_Impl::metaname ("Latency");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Latency Latency_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < Latency > (parent, Latency_Impl::metaname);
  }

  //
  // _create (const MetricsBase_in)
  //
  Latency Latency_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create_object < Latency > (parent, Latency_Impl::metaname);
  }

  //
  // accept
  //
  void Latency_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Latency (this);
    else
      v->visit_Model (this);
  }
}

