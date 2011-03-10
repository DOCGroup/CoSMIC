// $Id$

#include "stdafx.h"
#include "WorkLoadOperationConnection.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/Task.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkLoadOperationConnection_Impl::metaname = "WorkLoadOperationConnection";

  //
  // WorkLoadOperationConnection_Impl
  //
  WorkLoadOperationConnection_Impl::WorkLoadOperationConnection_Impl (void)
  {
  }

  //
  // WorkLoadOperationConnection_Impl
  //
  WorkLoadOperationConnection_Impl::WorkLoadOperationConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkLoadOperationConnection_Impl
  //
  WorkLoadOperationConnection_Impl::~WorkLoadOperationConnection_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkLoadOperationConnection_Impl::accept (Visitor * v)
  {
    v->visit_WorkLoadOperationConnection (this);
  }

  //
  // _create
  //
  WorkLoadOperationConnection WorkLoadOperationConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <WorkLoadOperationConnection> (parent, WorkLoadOperationConnection_Impl::metaname);
  }

  //
  // src_OperationRef
  //
  OperationRef WorkLoadOperationConnection_Impl::src_OperationRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return OperationRef::_narrow (target);
  }

  //
  // dst_Task
  //
  Task WorkLoadOperationConnection_Impl::dst_Task (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Task::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis WorkLoadOperationConnection_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

