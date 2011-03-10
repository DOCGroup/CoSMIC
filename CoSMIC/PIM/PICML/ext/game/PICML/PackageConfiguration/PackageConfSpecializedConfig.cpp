// $Id$

#include "stdafx.h"
#include "PackageConfSpecializedConfig.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfSpecializedConfig_Impl::metaname = "PackageConfSpecializedConfig";

  //
  // PackageConfSpecializedConfig_Impl
  //
  PackageConfSpecializedConfig_Impl::PackageConfSpecializedConfig_Impl (void)
  {
  }

  //
  // PackageConfSpecializedConfig_Impl
  //
  PackageConfSpecializedConfig_Impl::PackageConfSpecializedConfig_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfSpecializedConfig_Impl
  //
  PackageConfSpecializedConfig_Impl::~PackageConfSpecializedConfig_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfSpecializedConfig_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfSpecializedConfig (this);
  }

  //
  // _create
  //
  PackageConfSpecializedConfig PackageConfSpecializedConfig_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfSpecializedConfig> (parent, PackageConfSpecializedConfig_Impl::metaname);
  }

  //
  // src_PackageConfiguration
  //
  PackageConfiguration PackageConfSpecializedConfig_Impl::src_PackageConfiguration (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return PackageConfiguration::_narrow (target);
  }

  //
  // dst_PackageConfigurationReference
  //
  PackageConfigurationReference PackageConfSpecializedConfig_Impl::dst_PackageConfigurationReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return PackageConfigurationReference::_narrow (target);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfSpecializedConfig_Impl::parent_PackageConfigurationContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurationContainer> (this->object_.p);
  }
}

