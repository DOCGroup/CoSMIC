// $Id$

#include "stdafx.h"
#include "OperationRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/OperationTypes/OperationBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OperationRef_Impl::metaname = "OperationRef";

  //
  // OperationRef_Impl
  //
  OperationRef_Impl::OperationRef_Impl (void)
  {
  }

  //
  // OperationRef_Impl
  //
  OperationRef_Impl::OperationRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OperationRef_Impl
  //
  OperationRef_Impl::~OperationRef_Impl (void)
  {
  }

  //
  // accept
  //
  void OperationRef_Impl::accept (Visitor * v)
  {
    v->visit_OperationRef (this);
  }

  //
  // _create
  //
  OperationRef OperationRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <OperationRef> (parent, OperationRef_Impl::metaname);
  }

  //
  // in_WorkLoadOperationConnection_connections
  //
  size_t OperationRef_Impl::in_WorkLoadOperationConnection_connections (std::vector <WorkLoadOperationConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ComponentOperation_connections
  //
  size_t OperationRef_Impl::in_ComponentOperation_connections (std::vector <ComponentOperation> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_MetricConnection_connections
  //
  size_t OperationRef_Impl::in_MetricConnection_connections (std::vector <MetricConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_TimerConnection_connections
  //
  size_t OperationRef_Impl::in_TimerConnection_connections (std::vector <TimerConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis OperationRef_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

