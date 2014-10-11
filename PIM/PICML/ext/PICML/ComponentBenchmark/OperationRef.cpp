// $Id$

#include "StdAfx.h"
#include "OperationRef.h"

#if !defined (__GAME_INLINE__)
#include "OperationRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/LookupOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string OperationRef_Impl::metaname ("OperationRef");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  OperationRef OperationRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < OperationRef > (parent, OperationRef_Impl::metaname);
  }

  //
  // accept
  //
  void OperationRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OperationRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis OperationRef_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // src_WorkLoadOperationConnection
  //
  size_t OperationRef_Impl::src_WorkLoadOperationConnection (std::vector <WorkLoadOperationConnection> & items) const
  {
    return this->in_connections <WorkLoadOperationConnection> (items);
  }

  //
  // src_ComponentOperation
  //
  size_t OperationRef_Impl::src_ComponentOperation (std::vector <ComponentOperation> & items) const
  {
    return this->in_connections <ComponentOperation> (items);
  }

  //
  // src_MetricConnection
  //
  size_t OperationRef_Impl::src_MetricConnection (std::vector <MetricConnection> & items) const
  {
    return this->in_connections <MetricConnection> (items);
  }

  //
  // src_TimerConnection
  //
  size_t OperationRef_Impl::src_TimerConnection (std::vector <TimerConnection> & items) const
  {
    return this->in_connections <TimerConnection> (items);
  }

  //
  // OperationBase_is_nil
  //
  bool OperationRef_Impl::OperationBase_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_OperationBase
  //
  void OperationRef_Impl::set_OperationBase (OperationBase_in item)
  {
    this->refers_to (item);
  }

  //
  // get_OperationBase
  //
  OperationBase OperationRef_Impl::get_OperationBase (void) const
  {
    return OperationBase::_narrow (this->refers_to ());
  }
}

