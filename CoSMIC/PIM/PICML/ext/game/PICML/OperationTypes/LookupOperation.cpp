// $Id$

#include "StdAfx.h"
#include "LookupOperation.h"

#if !defined (__GAME_INLINE__)
#include "LookupOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string LookupOperation_Impl::metaname ("LookupOperation");

  //
  // _create (const ComponentFactory_in)
  //
  LookupOperation LookupOperation_Impl::_create (const ComponentFactory_in parent)
  {
    return ::GAME::Mga::create_object < LookupOperation > (parent, LookupOperation_Impl::metaname);
  }

  //
  // _create (const HasExceptions_in)
  //
  LookupOperation LookupOperation_Impl::_create (const HasExceptions_in parent)
  {
    return ::GAME::Mga::create_object < LookupOperation > (parent, LookupOperation_Impl::metaname);
  }

  //
  // accept
  //
  void LookupOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LookupOperation (this);
    else
      v->visit_Model (this);
  }
}

