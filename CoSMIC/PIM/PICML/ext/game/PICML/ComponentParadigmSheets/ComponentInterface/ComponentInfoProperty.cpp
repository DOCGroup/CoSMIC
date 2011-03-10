// $Id$

#include "stdafx.h"
#include "ComponentInfoProperty.h"

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
  const std::string ComponentInfoProperty_Impl::metaname = "ComponentInfoProperty";

  //
  // ComponentInfoProperty_Impl
  //
  ComponentInfoProperty_Impl::ComponentInfoProperty_Impl (void)
  {
  }

  //
  // ComponentInfoProperty_Impl
  //
  ComponentInfoProperty_Impl::ComponentInfoProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInfoProperty_Impl
  //
  ComponentInfoProperty_Impl::~ComponentInfoProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentInfoProperty_Impl::accept (Visitor * v)
  {
    v->visit_ComponentInfoProperty (this);
  }

  //
  // _create
  //
  ComponentInfoProperty ComponentInfoProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComponentInfoProperty> (parent, ComponentInfoProperty_Impl::metaname);
  }

  //
  // src_ComponentRef
  //
  ComponentRef ComponentInfoProperty_Impl::src_ComponentRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentRef::_narrow (target);
  }

  //
  // dst_Property
  //
  Property ComponentInfoProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentInfoProperty_Impl::parent_ComponentContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentContainer> (this->object_.p);
  }
}

