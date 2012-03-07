// $Id$

#include "StdAfx.h"
#include "WorkLoadOperationConnection.h"

#if !defined (__GAME_INLINE__)
#include "WorkLoadOperationConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkLoadOperationConnection_Impl::metaname ("WorkLoadOperationConnection");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  WorkLoadOperationConnection WorkLoadOperationConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < WorkLoadOperationConnection > (parent, WorkLoadOperationConnection_Impl::metaname);
  }

  //
  // accept
  //
  void WorkLoadOperationConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_WorkLoadOperationConnection (this);
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
  OperationRef WorkLoadOperationConnection_Impl::src_OperationRef (void) const
  {
    return OperationRef::_narrow (this->src ());
  }

  //
  // Task
  //
  Task WorkLoadOperationConnection_Impl::dst_Task (void) const
  {
    return Task::_narrow (this->dst ());
  }
}

