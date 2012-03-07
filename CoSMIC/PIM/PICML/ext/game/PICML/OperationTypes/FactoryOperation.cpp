// $Id$

#include "StdAfx.h"
#include "FactoryOperation.h"

#if !defined (__GAME_INLINE__)
#include "FactoryOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/OperationTypes/HasExceptions.h"
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
  // _create (const ComponentFactory_in)
  //
  FactoryOperation FactoryOperation_Impl::_create (const ComponentFactory_in parent)
  {
    return ::GAME::Mga::create_object < FactoryOperation > (parent, FactoryOperation_Impl::metaname);
  }

  //
  // _create (const ObjectByValue_in)
  //
  FactoryOperation FactoryOperation_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create_object < FactoryOperation > (parent, FactoryOperation_Impl::metaname);
  }

  //
  // _create (const HasExceptions_in)
  //
  FactoryOperation FactoryOperation_Impl::_create (const HasExceptions_in parent)
  {
    return ::GAME::Mga::create_object < FactoryOperation > (parent, FactoryOperation_Impl::metaname);
  }

  //
  // accept
  //
  void FactoryOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_FactoryOperation (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

