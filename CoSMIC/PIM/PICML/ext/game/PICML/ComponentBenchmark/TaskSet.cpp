// $Id$

#include "stdafx.h"
#include "TaskSet.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TaskSet_Impl::metaname = "TaskSet";

  //
  // TaskSet_Impl
  //
  TaskSet_Impl::TaskSet_Impl (void)
  {
  }

  //
  // TaskSet_Impl
  //
  TaskSet_Impl::TaskSet_Impl (IMgaSet * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TaskSet_Impl
  //
  TaskSet_Impl::~TaskSet_Impl (void)
  {
  }

  //
  // accept
  //
  void TaskSet_Impl::accept (Visitor * v)
  {
    v->visit_TaskSet (this);
  }

  //
  // _create
  //
  TaskSet TaskSet_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <TaskSet> (parent, TaskSet_Impl::metaname);
  }

  //
  // rate
  //
  void TaskSet_Impl::rate (long val)
  {
    static const std::string attr_rate ("rate");
    this->attribute (attr_rate)->int_value (val);
  }

  //
  // rate
  //
  long TaskSet_Impl::rate (void) const
  {
    static const std::string attr_rate ("rate");
    return this->attribute (attr_rate)->int_value ();
  }

  //
  // priority
  //
  void TaskSet_Impl::priority (long val)
  {
    static const std::string attr_priority ("priority");
    this->attribute (attr_priority)->int_value (val);
  }

  //
  // priority
  //
  long TaskSet_Impl::priority (void) const
  {
    static const std::string attr_priority ("priority");
    return this->attribute (attr_priority)->int_value ();
  }

  //
  // in_WorkloadCharacteristics_connections
  //
  size_t TaskSet_Impl::in_WorkloadCharacteristics_connections (std::vector <WorkloadCharacteristics> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TaskSet_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

