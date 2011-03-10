// $Id$

#include "stdafx.h"
#include "PackageInfoProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageInfoProperty_Impl::metaname = "PackageInfoProperty";

  //
  // PackageInfoProperty_Impl
  //
  PackageInfoProperty_Impl::PackageInfoProperty_Impl (void)
  {
  }

  //
  // PackageInfoProperty_Impl
  //
  PackageInfoProperty_Impl::PackageInfoProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageInfoProperty_Impl
  //
  PackageInfoProperty_Impl::~PackageInfoProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageInfoProperty_Impl::accept (Visitor * v)
  {
    v->visit_PackageInfoProperty (this);
  }

  //
  // _create
  //
  PackageInfoProperty PackageInfoProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageInfoProperty> (parent, PackageInfoProperty_Impl::metaname);
  }

  //
  // src_ComponentPackage
  //
  ComponentPackage PackageInfoProperty_Impl::src_ComponentPackage (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentPackage::_narrow (target);
  }

  //
  // dst_Property
  //
  Property PackageInfoProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer PackageInfoProperty_Impl::parent_PackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageContainer> (this->object_.p);
  }
}

