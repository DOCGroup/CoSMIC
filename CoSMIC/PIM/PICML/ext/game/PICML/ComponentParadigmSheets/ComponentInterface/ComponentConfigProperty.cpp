// $Id$

#include "stdafx.h"
#include "ComponentConfigProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentConfigProperty_Impl::metaname = "ComponentConfigProperty";

  //
  // ComponentConfigProperty_Impl
  //
  ComponentConfigProperty_Impl::ComponentConfigProperty_Impl (void)
  {
  }

  //
  // ComponentConfigProperty_Impl
  //
  ComponentConfigProperty_Impl::ComponentConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentConfigProperty_Impl
  //
  ComponentConfigProperty_Impl::~ComponentConfigProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentConfigProperty_Impl::accept (Visitor * v)
  {
    v->visit_ComponentConfigProperty (this);
  }

  //
  // _create
  //
  ComponentConfigProperty ComponentConfigProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComponentConfigProperty> (parent, ComponentConfigProperty_Impl::metaname);
  }

  //
  // src_ComponentRef
  //
  ComponentRef ComponentConfigProperty_Impl::src_ComponentRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentRef::_narrow (target);
  }

  //
  // dst_Property
  //
  Property ComponentConfigProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentConfigProperty_Impl::parent_ComponentContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentContainer> (this->object_.p);
  }
}

