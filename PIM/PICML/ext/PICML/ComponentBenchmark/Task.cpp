// $Id$

#include "StdAfx.h"
#include "Task.h"

#if !defined (__GAME_INLINE__)
#include "Task.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Task_Impl::metaname ("Task");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Task Task_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < Task > (parent, Task_Impl::metaname);
  }

  //
  // accept
  //
  void Task_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Task (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis Task_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // dst_of_WorkLoadOperationConnection
  //
  size_t Task_Impl::dst_of_WorkLoadOperationConnection (std::vector <WorkLoadOperationConnection> & items) const
  {
    return this->in_connections <WorkLoadOperationConnection> (items);
  }

  //
  // dst_of_WorkLoadOperationConnection
  //
  GAME::Mga::Collection_T <WorkLoadOperationConnection> Task_Impl::dst_of_WorkLoadOperationConnection (void) const
  {
    return this->in_connections <WorkLoadOperationConnection> ("dst");
  }
}

