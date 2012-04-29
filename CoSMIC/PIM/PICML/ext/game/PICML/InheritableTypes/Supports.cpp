// $Id$

#include "StdAfx.h"
#include "Supports.h"

#if !defined (__GAME_INLINE__)
#include "Supports.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "PICML/InheritableTypes/Supports.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Supports_Impl::metaname ("Supports");

  //
  // _create (const SupportsInterfaces_in)
  //
  Supports Supports_Impl::_create (const SupportsInterfaces_in parent)
  {
    return ::GAME::Mga::create_object < Supports > (parent, Supports_Impl::metaname);
  }

  //
  // accept
  //
  void Supports_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Supports (this);
    else
      v->visit_Reference (this);
  }

  //
  // Object_is_nil
  //
  bool Supports_Impl::Object_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Object
  //
  Object Supports_Impl::get_Object (void) const
  {
    return Object::_narrow (this->refers_to ());
  }

  //
  // Supports_is_nil
  //
  bool Supports_Impl::Supports_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Supports
  //
  Supports Supports_Impl::get_Supports (void) const
  {
    return Supports::_narrow (this->refers_to ());
  }
}

