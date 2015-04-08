#include "StdAfx.h"
#include "OperationRef.h"

#if !defined (__GAME_INLINE__)
#include "OperationRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/OperationTypes/LookupOperation.h"
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
  // is_abstract
  //
  const bool OperationRef_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in)
  //
  OperationRef OperationRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < OperationRef > (parent, OperationRef_Impl::metaname);
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
  // src_of_WorkLoadOperationConnection
  //
  size_t OperationRef_Impl::src_of_WorkLoadOperationConnection (std::vector <WorkLoadOperationConnection> & items) const
  {
    return this->in_connections <WorkLoadOperationConnection> (items);
  }

  //
  // has_src_of_WorkLoadOperationConnection
  //
  bool OperationRef_Impl::has_src_of_WorkLoadOperationConnection (void) const
  {
    return this->in_connections <WorkLoadOperationConnection> ("src").count () == 1;
  }

  //
  // src_of_WorkLoadOperationConnection
  //
  WorkLoadOperationConnection OperationRef_Impl::src_of_WorkLoadOperationConnection (void) const
  {
    return this->in_connections <WorkLoadOperationConnection> ("src").first ();
  }

  //
  // src_of_ComponentOperation
  //
  size_t OperationRef_Impl::src_of_ComponentOperation (std::vector <ComponentOperation> & items) const
  {
    return this->in_connections <ComponentOperation> (items);
  }

  //
  // has_src_of_ComponentOperation
  //
  bool OperationRef_Impl::has_src_of_ComponentOperation (void) const
  {
    return this->in_connections <ComponentOperation> ("src").count () == 1;
  }

  //
  // src_of_ComponentOperation
  //
  ComponentOperation OperationRef_Impl::src_of_ComponentOperation (void) const
  {
    return this->in_connections <ComponentOperation> ("src").first ();
  }

  //
  // src_of_MetricConnection
  //
  size_t OperationRef_Impl::src_of_MetricConnection (std::vector <MetricConnection> & items) const
  {
    return this->in_connections <MetricConnection> (items);
  }

  //
  // has_src_of_MetricConnection
  //
  bool OperationRef_Impl::has_src_of_MetricConnection (void) const
  {
    return this->in_connections <MetricConnection> ("src").count () == 1;
  }

  //
  // src_of_MetricConnection
  //
  MetricConnection OperationRef_Impl::src_of_MetricConnection (void) const
  {
    return this->in_connections <MetricConnection> ("src").first ();
  }

  //
  // src_of_TimerConnection
  //
  size_t OperationRef_Impl::src_of_TimerConnection (std::vector <TimerConnection> & items) const
  {
    return this->in_connections <TimerConnection> (items);
  }

  //
  // has_src_of_TimerConnection
  //
  bool OperationRef_Impl::has_src_of_TimerConnection (void) const
  {
    return this->in_connections <TimerConnection> ("src").count () == 1;
  }

  //
  // src_of_TimerConnection
  //
  TimerConnection OperationRef_Impl::src_of_TimerConnection (void) const
  {
    return this->in_connections <TimerConnection> ("src").first ();
  }

  //
  // OperationBase_is_nil
  //
  bool OperationRef_Impl::OperationBase_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_OperationBase
  //
  void OperationRef_Impl::refers_to_OperationBase (OperationBase_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_OperationBase
  //
  OperationBase OperationRef_Impl::refers_to_OperationBase (void) const
  {
    return OperationBase::_narrow (this->refers_to ());
  }
}

