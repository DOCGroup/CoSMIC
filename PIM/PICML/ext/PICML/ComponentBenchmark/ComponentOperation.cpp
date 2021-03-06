#include "StdAfx.h"
#include "ComponentOperation.h"

#if !defined (__GAME_INLINE__)
#include "ComponentOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/CompRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentOperation_Impl::metaname ("ComponentOperation");

  //
  // is_abstract
  //
  const bool ComponentOperation_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in, OperationRef_in src, CompRef_in dst)
  //
  ComponentOperation ComponentOperation_Impl::_create (const BenchmarkAnalysis_in parent, OperationRef_in src, CompRef_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ComponentOperation_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void ComponentOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentOperation (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis ComponentOperation_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // OperationRef
  //
  OperationRef ComponentOperation_Impl::src_OperationRef (void) const
  {
    return OperationRef::_narrow (this->src ());
  }

  //
  // CompRef
  //
  CompRef ComponentOperation_Impl::dst_CompRef (void) const
  {
    return CompRef::_narrow (this->dst ());
  }
}

