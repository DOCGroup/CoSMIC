// $Id$

#include "StdAfx.h"
#include "BenchmarkCharacteristics.h"

#if !defined (__GAME_INLINE__)
#include "BenchmarkCharacteristics.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "PICML/ComponentBenchmark/PeriodicBenchmarks.h"
#include "PICML/ComponentBenchmark/FixedIterationBenchmarks.h"
#include "PICML/ComponentBenchmark/TriggerBenchmarks.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/Throughput.h"
#include "PICML/ComponentBenchmark/Latency.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkCharacteristics_Impl::metaname ("BenchmarkCharacteristics");

  //
  // is_abstract
  //
  const bool BenchmarkCharacteristics_Impl::is_abstract (0);

  //
  // _create (const BenchmarkAnalysis_in, BenchmarkType_in src, MetricsBase_in dst)
  //
  BenchmarkCharacteristics BenchmarkCharacteristics_Impl::_create (const BenchmarkAnalysis_in parent, BenchmarkType_in src, MetricsBase_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, BenchmarkCharacteristics_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void BenchmarkCharacteristics_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_BenchmarkCharacteristics (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis BenchmarkCharacteristics_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // BenchmarkType
  //
  BenchmarkType BenchmarkCharacteristics_Impl::src_BenchmarkType (void) const
  {
    return BenchmarkType::_narrow (this->src ());
  }

  //
  // MetricsBase
  //
  MetricsBase BenchmarkCharacteristics_Impl::dst_MetricsBase (void) const
  {
    return MetricsBase::_narrow (this->dst ());
  }
}

