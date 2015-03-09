// $Id$

#include "StdAfx.h"
#include "OnewayOperation.h"

#if !defined (__GAME_INLINE__)
#include "OnewayOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
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
  // is_abstract
  //
  const bool OnewayOperation_Impl::is_abstract = false;

  //
  // _create (const HasOperations_in)
  //
  OnewayOperation OnewayOperation_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create < OnewayOperation > (parent, OnewayOperation_Impl::metaname);
  }

  //
  // _create (const BenchmarkAnalysis_in)
  //
  OnewayOperation OnewayOperation_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < OnewayOperation > (parent, OnewayOperation_Impl::metaname);
  }

  //
  // accept
  //
  void OnewayOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OnewayOperation (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_HasOperations
  //
  HasOperations OnewayOperation_Impl::parent_HasOperations (void)
  {
    return HasOperations::_narrow (this->parent ());
  }
}

