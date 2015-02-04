// $Id$

#include "StdAfx.h"
#include "ComponentProperty.h"

#if !defined (__GAME_INLINE__)
#include "ComponentProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentProperty_Impl::metaname ("ComponentProperty");

  //
  // is_abstract
  //
  const bool ComponentProperty_Impl::is_abstract = false;

  //
  // _create (const ComponentContainer_in, ComponentRef_in src, ComponentPropertyDescription_in dst)
  //
  ComponentProperty ComponentProperty_Impl::_create (const ComponentContainer_in parent, ComponentRef_in src, ComponentPropertyDescription_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ComponentProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void ComponentProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentProperty_Impl::parent_ComponentContainer (void)
  {
    return ComponentContainer::_narrow (this->parent ());
  }

  //
  // ComponentRef
  //
  ComponentRef ComponentProperty_Impl::src_ComponentRef (void) const
  {
    return ComponentRef::_narrow (this->src ());
  }

  //
  // ComponentPropertyDescription
  //
  ComponentPropertyDescription ComponentProperty_Impl::dst_ComponentPropertyDescription (void) const
  {
    return ComponentPropertyDescription::_narrow (this->dst ());
  }
}

