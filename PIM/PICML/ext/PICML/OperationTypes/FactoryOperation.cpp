// $Id$

#include "StdAfx.h"
#include "FactoryOperation.h"

#if !defined (__GAME_INLINE__)
#include "FactoryOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string FactoryOperation_Impl::metaname ("FactoryOperation");

  //
  // is_abstract
  //
  const bool FactoryOperation_Impl::is_abstract = false;

  //
  // _create (const ObjectByValue_in)
  //
  FactoryOperation FactoryOperation_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create < FactoryOperation > (parent, FactoryOperation_Impl::metaname);
  }

  //
  // _create (const ComponentFactory_in)
  //
  FactoryOperation FactoryOperation_Impl::_create (const ComponentFactory_in parent)
  {
    return ::GAME::Mga::create < FactoryOperation > (parent, FactoryOperation_Impl::metaname);
  }

  //
  // _create (const BenchmarkAnalysis_in)
  //
  FactoryOperation FactoryOperation_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < FactoryOperation > (parent, FactoryOperation_Impl::metaname);
  }

  //
  // accept
  //
  void FactoryOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_FactoryOperation (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ObjectByValue
  //
  ObjectByValue FactoryOperation_Impl::parent_ObjectByValue (void)
  {
    return ObjectByValue::_narrow (this->parent ());
  }

  //
  // parent_ComponentFactory
  //
  ComponentFactory FactoryOperation_Impl::parent_ComponentFactory (void)
  {
    return ComponentFactory::_narrow (this->parent ());
  }
}

