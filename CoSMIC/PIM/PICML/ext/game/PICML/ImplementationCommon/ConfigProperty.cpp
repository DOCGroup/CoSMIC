// $Id$

#include "stdafx.h"
#include "ConfigProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ImplementationCommon/Implemenation.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConfigProperty_Impl::metaname = "ConfigProperty";

  //
  // ConfigProperty_Impl
  //
  ConfigProperty_Impl::ConfigProperty_Impl (void)
  {
  }

  //
  // ConfigProperty_Impl
  //
  ConfigProperty_Impl::ConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConfigProperty_Impl
  //
  ConfigProperty_Impl::~ConfigProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void ConfigProperty_Impl::accept (Visitor * v)
  {
    v->visit_ConfigProperty (this);
  }

  //
  // _create
  //
  ConfigProperty ConfigProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ConfigProperty> (parent, ConfigProperty_Impl::metaname);
  }

  //
  // src_Implemenation
  //
  Implemenation ConfigProperty_Impl::src_Implemenation (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Implemenation::_narrow (target);
  }

  //
  // dst_Property
  //
  Property ConfigProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer ConfigProperty_Impl::parent_ImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ImplementationContainer> (this->object_.p);
  }
}

