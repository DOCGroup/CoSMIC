// $Id$

#include "stdafx.h"
#include "InfoProperty.h"

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
  const std::string InfoProperty_Impl::metaname = "InfoProperty";

  //
  // InfoProperty_Impl
  //
  InfoProperty_Impl::InfoProperty_Impl (void)
  {
  }

  //
  // InfoProperty_Impl
  //
  InfoProperty_Impl::InfoProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InfoProperty_Impl
  //
  InfoProperty_Impl::~InfoProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void InfoProperty_Impl::accept (Visitor * v)
  {
    v->visit_InfoProperty (this);
  }

  //
  // _create
  //
  InfoProperty InfoProperty_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <InfoProperty> (parent, InfoProperty_Impl::metaname);
  }

  //
  // src_Implemenation
  //
  Implemenation InfoProperty_Impl::src_Implemenation (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Implemenation::_narrow (target);
  }

  //
  // dst_Property
  //
  Property InfoProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer InfoProperty_Impl::parent_ImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ImplementationContainer> (this->object_.p);
  }
}

