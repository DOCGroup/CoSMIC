// $Id$

#include "stdafx.h"
#include "PackageConfConfigProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfConfigProperty_Impl::metaname = "PackageConfConfigProperty";

  //
  // PackageConfConfigProperty_Impl
  //
  PackageConfConfigProperty_Impl::PackageConfConfigProperty_Impl (void)
  {
  }

  //
  // PackageConfConfigProperty_Impl
  //
  PackageConfConfigProperty_Impl::PackageConfConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfConfigProperty_Impl
  //
  PackageConfConfigProperty_Impl::~PackageConfConfigProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfConfigProperty_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfConfigProperty (this);
  }

  //
  // _create
  //
  PackageConfConfigProperty PackageConfConfigProperty_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfConfigProperty> (parent, PackageConfConfigProperty_Impl::metaname);
  }

  //
  // src_PackageConfiguration
  //
  PackageConfiguration PackageConfConfigProperty_Impl::src_PackageConfiguration (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return PackageConfiguration::_narrow (target);
  }

  //
  // dst_Property
  //
  Property PackageConfConfigProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfConfigProperty_Impl::parent_PackageConfigurationContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurationContainer> (this->object_.p);
  }
}

