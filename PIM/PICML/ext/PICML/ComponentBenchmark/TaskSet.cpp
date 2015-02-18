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
  // is_abstract
  //
  const bool TaskSet_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in)
  //
  TaskSet TaskSet_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < TaskSet > (parent, TaskSet_Impl::metaname);
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
  // dst_of_WorkloadCharacteristics
  //
  size_t TaskSet_Impl::dst_of_WorkloadCharacteristics (std::vector <WorkloadCharacteristics> & items) const
  {
    return this->in_connections <WorkloadCharacteristics> (items);
  }

  //
  // has_dst_of_WorkloadCharacteristics
  //
  bool TaskSet_Impl::has_dst_of_WorkloadCharacteristics (void) const
  {
    return this->in_connections <WorkloadCharacteristics> ("dst").count () == 1;
  }

  //
  // dst_of_WorkloadCharacteristics
  //
  WorkloadCharacteristics TaskSet_Impl::dst_of_WorkloadCharacteristics (void) const
  {
    return this->in_connections <WorkloadCharacteristics> ("dst").first ();
  }

  //
  // members_Task
  //
  ::GAME::Mga::Collection_T <Task> TaskSet_Impl::members_Task (void)
  {
    return this->members <Task> ();
  }
}

