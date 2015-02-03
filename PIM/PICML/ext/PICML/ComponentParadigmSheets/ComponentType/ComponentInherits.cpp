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
  // is_abstract
  //
  const bool ComponentInherits_Impl::is_abstract (0);

  //
  // _create (const Component_in)
  //
  ComponentInherits ComponentInherits_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create < ComponentInherits > (parent, ComponentInherits_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInherits_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentInherits (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Component
  //
  Component ComponentInherits_Impl::parent_Component (void)
  {
    return Component::_narrow (this->parent ());
  }

  //
  // Component_is_nil
  //
  bool ComponentInherits_Impl::Component_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_Component
  //
  void ComponentInherits_Impl::refers_to_Component (Component_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Component
  //
  Component ComponentInherits_Impl::refers_to_Component (void) const
  {
    return Component::_narrow (this->refers_to ());
  }
}

