// $Id$

#include "StdAfx.h"
#include "Inherits.h"

#if !defined (__GAME_INLINE__)
#include "Inherits.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
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
    return ::GAME::Mga::create < Inherits > (parent, Inherits_Impl::metaname);
  }

  //
  // accept
  //
  void Inherits_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Inherits (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Inheritable
  //
  Inheritable Inherits_Impl::parent_Inheritable (void)
  {
    return Inheritable::_narrow (this->parent ());
  }

  //
  // Inheritable_is_nil
  //
  bool Inherits_Impl::Inheritable_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_Inheritable
  //
  void Inherits_Impl::refers_to_Inheritable (Inheritable_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Inheritable
  //
  Inheritable Inherits_Impl::refers_to_Inheritable (void) const
  {
    return Inheritable::_narrow (this->refers_to ());
  }
}

