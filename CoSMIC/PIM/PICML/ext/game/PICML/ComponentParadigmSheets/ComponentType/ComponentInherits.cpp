// $Id$

#include "StdAfx.h"
#include "ComponentInherits.h"

#if !defined (__GAME_INLINE__)
#include "ComponentInherits.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInherits_Impl::metaname ("ComponentInherits");

  //
  // _create (const Component_in)
  //
  ComponentInherits ComponentInherits_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object < ComponentInherits > (parent, ComponentInherits_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInherits_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentInherits (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // Component_is_nil
  //
  bool ComponentInherits_Impl::Component_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Component
  //
  Component ComponentInherits_Impl::get_Component (void) const
  {
    return Component::_narrow (this->refers_to ());
  }
}

