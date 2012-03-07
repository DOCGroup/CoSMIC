// $Id$

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
  // _create (const BenchmarkAnalysis_in)
  //
  ComponentOperation ComponentOperation_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < ComponentOperation > (parent, ComponentOperation_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentOperation (this);
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

