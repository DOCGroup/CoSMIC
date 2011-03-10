// $Id$

#include "stdafx.h"
#include "ComponentProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentProperty_Impl::metaname = "ComponentProperty";

  //
  // ComponentProperty_Impl
  //
  ComponentProperty_Impl::ComponentProperty_Impl (void)
  {
  }

  //
  // ComponentProperty_Impl
  //
  ComponentProperty_Impl::ComponentProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentProperty_Impl
  //
  ComponentProperty_Impl::~ComponentProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentProperty_Impl::accept (Visitor * v)
  {
    v->visit_ComponentProperty (this);
  }

  //
  // _create
  //
  ComponentProperty ComponentProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComponentProperty> (parent, ComponentProperty_Impl::metaname);
  }

  //
  // src_ComponentRef
  //
  ComponentRef ComponentProperty_Impl::src_ComponentRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentRef::_narrow (target);
  }

  //
  // dst_ComponentPropertyDescription
  //
  ComponentPropertyDescription ComponentProperty_Impl::dst_ComponentPropertyDescription (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentPropertyDescription::_narrow (target);
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentProperty_Impl::parent_ComponentContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentContainer> (this->object_.p);
  }
}

