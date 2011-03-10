// $Id$

#include "stdafx.h"
#include "ComponentOperation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/CompRef.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentOperation_Impl::metaname = "ComponentOperation";

  //
  // ComponentOperation_Impl
  //
  ComponentOperation_Impl::ComponentOperation_Impl (void)
  {
  }

  //
  // ComponentOperation_Impl
  //
  ComponentOperation_Impl::ComponentOperation_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentOperation_Impl
  //
  ComponentOperation_Impl::~ComponentOperation_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentOperation_Impl::accept (Visitor * v)
  {
    v->visit_ComponentOperation (this);
  }

  //
  // _create
  //
  ComponentOperation ComponentOperation_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <ComponentOperation> (parent, ComponentOperation_Impl::metaname);
  }

  //
  // src_OperationRef
  //
  OperationRef ComponentOperation_Impl::src_OperationRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return OperationRef::_narrow (target);
  }

  //
  // dst_CompRef
  //
  CompRef ComponentOperation_Impl::dst_CompRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return CompRef::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis ComponentOperation_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

