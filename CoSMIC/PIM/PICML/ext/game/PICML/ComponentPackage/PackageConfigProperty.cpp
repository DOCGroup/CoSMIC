// $Id$

#include "stdafx.h"
#include "PackageConfigProperty.h"

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
  const std::string PackageConfigProperty_Impl::metaname = "PackageConfigProperty";

  //
  // PackageConfigProperty_Impl
  //
  PackageConfigProperty_Impl::PackageConfigProperty_Impl (void)
  {
  }

  //
  // PackageConfigProperty_Impl
  //
  PackageConfigProperty_Impl::PackageConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfigProperty_Impl
  //
  PackageConfigProperty_Impl::~PackageConfigProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfigProperty_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfigProperty (this);
  }

  //
  // _create
  //
  PackageConfigProperty PackageConfigProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfigProperty> (parent, PackageConfigProperty_Impl::metaname);
  }

  //
  // src_ComponentPackage
  //
  ComponentPackage PackageConfigProperty_Impl::src_ComponentPackage (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentPackage::_narrow (target);
  }

  //
  // dst_Property
  //
  Property PackageConfigProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer PackageConfigProperty_Impl::parent_PackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageContainer> (this->object_.p);
  }
}

