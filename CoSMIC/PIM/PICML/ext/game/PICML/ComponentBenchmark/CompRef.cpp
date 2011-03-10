// $Id$

#include "stdafx.h"
#include "CompRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CompRef_Impl::metaname = "CompRef";

  //
  // CompRef_Impl
  //
  CompRef_Impl::CompRef_Impl (void)
  {
  }

  //
  // CompRef_Impl
  //
  CompRef_Impl::CompRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CompRef_Impl
  //
  CompRef_Impl::~CompRef_Impl (void)
  {
  }

  //
  // accept
  //
  void CompRef_Impl::accept (Visitor * v)
  {
    v->visit_CompRef (this);
  }

  //
  // _create
  //
  CompRef CompRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <CompRef> (parent, CompRef_Impl::metaname);
  }

  //
  // in_ComponentOperation_connections
  //
  size_t CompRef_Impl::in_ComponentOperation_connections (std::vector <ComponentOperation> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis CompRef_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

