// $Id$

#include "StdAfx.h"
#include "OnewayOperation.h"

#if !defined (__GAME_INLINE__)
#include "OnewayOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string OnewayOperation_Impl::metaname ("OnewayOperation");

  //
  // _create (const HasOperations_in)
  //
  OnewayOperation OnewayOperation_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < OnewayOperation > (parent, OnewayOperation_Impl::metaname);
  }

  //
  // _create (const OperationBase_in)
  //
  OnewayOperation OnewayOperation_Impl::_create (const OperationBase_in parent)
  {
    return ::GAME::Mga::create_object < OnewayOperation > (parent, OnewayOperation_Impl::metaname);
  }

  //
  // _create (const BenchmarkAnalysis_in)
  //
  OnewayOperation OnewayOperation_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < OnewayOperation > (parent, OnewayOperation_Impl::metaname);
  }

  //
  // accept
  //
  void OnewayOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_OnewayOperation (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

