// $Id$

#include "stdafx.h"
#include "WorkloadCharacteristics.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/TaskSet.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkloadCharacteristics_Impl::metaname = "WorkloadCharacteristics";

  //
  // WorkloadCharacteristics_Impl
  //
  WorkloadCharacteristics_Impl::WorkloadCharacteristics_Impl (void)
  {
  }

  //
  // WorkloadCharacteristics_Impl
  //
  WorkloadCharacteristics_Impl::WorkloadCharacteristics_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkloadCharacteristics_Impl
  //
  WorkloadCharacteristics_Impl::~WorkloadCharacteristics_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkloadCharacteristics_Impl::accept (Visitor * v)
  {
    v->visit_WorkloadCharacteristics (this);
  }

  //
  // _create
  //
  WorkloadCharacteristics WorkloadCharacteristics_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <WorkloadCharacteristics> (parent, WorkloadCharacteristics_Impl::metaname);
  }

  //
  // src_MetricsBase
  //
  MetricsBase WorkloadCharacteristics_Impl::src_MetricsBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return MetricsBase::_narrow (target);
  }

  //
  // dst_TaskSet
  //
  TaskSet WorkloadCharacteristics_Impl::dst_TaskSet (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return TaskSet::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis WorkloadCharacteristics_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

