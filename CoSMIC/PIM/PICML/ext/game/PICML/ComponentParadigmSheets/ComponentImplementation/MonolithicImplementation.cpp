// $Id$

#include "StdAfx.h"
#include "MonolithicImplementation.h"

#if !defined (__GAME_INLINE__)
#include "MonolithicImplementation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithicImplementation_Impl::metaname ("MonolithicImplementation");

  //
  // _create (const ComponentImplementationContainer_in)
  //
  MonolithicImplementation MonolithicImplementation_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < MonolithicImplementation > (parent, MonolithicImplementation_Impl::metaname);
  }

  //
  // accept
  //
  void MonolithicImplementation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_MonolithicImplementation (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

