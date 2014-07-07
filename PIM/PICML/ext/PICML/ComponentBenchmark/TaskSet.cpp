// $Id$

#include "StdAfx.h"
#include "TaskSet.h"

#if !defined (__GAME_INLINE__)
#include "TaskSet.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TaskSet_Impl::metaname ("TaskSet");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  TaskSet TaskSet_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < TaskSet > (parent, TaskSet_Impl::metaname);
  }

  //
  // accept
  //
  void TaskSet_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TaskSet (this);
    else
      v->visit_Set (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TaskSet_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // dst_WorkloadCharacteristics
  //
  size_t TaskSet_Impl::dst_WorkloadCharacteristics (std::vector <WorkloadCharacteristics> & items) const
  {
    return this->in_connections <WorkloadCharacteristics> (items);
  }
}

