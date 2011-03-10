// $Id$

#include "stdafx.h"
#include "Task.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Task_Impl::metaname = "Task";

  //
  // Task_Impl
  //
  Task_Impl::Task_Impl (void)
  {
  }

  //
  // Task_Impl
  //
  Task_Impl::Task_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Task_Impl
  //
  Task_Impl::~Task_Impl (void)
  {
  }

  //
  // accept
  //
  void Task_Impl::accept (Visitor * v)
  {
    v->visit_Task (this);
  }

  //
  // _create
  //
  Task Task_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <Task> (parent, Task_Impl::metaname);
  }

  //
  // in_WorkLoadOperationConnection_connections
  //
  size_t Task_Impl::in_WorkLoadOperationConnection_connections (std::vector <WorkLoadOperationConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis Task_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

