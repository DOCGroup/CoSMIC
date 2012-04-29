// $Id$

#include "StdAfx.h"
#include "ComponentProperty.h"

#if !defined (__GAME_INLINE__)
#include "ComponentProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
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
  // _create (const ComponentContainer_in)
  //
  ComponentProperty ComponentProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentProperty > (parent, ComponentProperty_Impl::metaname);
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

