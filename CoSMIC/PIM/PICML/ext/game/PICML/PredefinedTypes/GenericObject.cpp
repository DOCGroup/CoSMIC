// $Id$

#include "StdAfx.h"
#include "GenericObject.h"

#if !defined (__GAME_INLINE__)
#include "GenericObject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string GenericObject_Impl::metaname ("GenericObject");

  //
  // _create (const PredefinedTypes_in)
  //
  GenericObject GenericObject_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create_root_object < GenericObject > (parent, GenericObject_Impl::metaname);
  }

  //
  // accept
  //
  void GenericObject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_GenericObject (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

