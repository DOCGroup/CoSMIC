// $Id$

#include "StdAfx.h"
#include "Inherits.h"

#if !defined (__GAME_INLINE__)
#include "Inherits.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Inherits_Impl::metaname ("Inherits");

  //
  // _create (const Inheritable_in)
  //
  Inherits Inherits_Impl::_create (const Inheritable_in parent)
  {
    return ::GAME::Mga::create_object < Inherits > (parent, Inherits_Impl::metaname);
  }

  //
  // accept
  //
  void Inherits_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Inherits (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // Inheritable_is_nil
  //
  bool Inherits_Impl::Inheritable_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Inheritable
  //
  Inheritable Inherits_Impl::get_Inheritable (void) const
  {
    return Inheritable::_narrow (this->refers_to ());
  }
}

