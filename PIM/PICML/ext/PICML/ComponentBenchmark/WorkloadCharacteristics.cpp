// $Id$

#include "StdAfx.h"
#include "WorkloadCharacteristics.h"

#if !defined (__GAME_INLINE__)
#include "WorkloadCharacteristics.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TaskSet.h"
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
  const std::string WorkloadCharacteristics_Impl::metaname ("WorkloadCharacteristics");

  //
  // is_abstract
  //
  const bool WorkloadCharacteristics_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in, MetricsBase_in src, TaskSet_in dst)
  //
  WorkloadCharacteristics WorkloadCharacteristics_Impl::_create (const BenchmarkAnalysis_in parent, MetricsBase_in src, TaskSet_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, WorkloadCharacteristics_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void WorkloadCharacteristics_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkloadCharacteristics (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis WorkloadCharacteristics_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // MetricsBase
  //
  MetricsBase WorkloadCharacteristics_Impl::src_MetricsBase (void) const
  {
    return MetricsBase::_narrow (this->src ());
  }

  //
  // TaskSet
  //
  TaskSet WorkloadCharacteristics_Impl::dst_TaskSet (void) const
  {
    return TaskSet::_narrow (this->dst ());
  }
}

