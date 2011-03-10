// $Id$

#include "stdafx.h"
#include "PackageConfBasePackage.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/ComponentPackage/ComponentPackage.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfBasePackage_Impl::metaname = "PackageConfBasePackage";

  //
  // PackageConfBasePackage_Impl
  //
  PackageConfBasePackage_Impl::PackageConfBasePackage_Impl (void)
  {
  }

  //
  // PackageConfBasePackage_Impl
  //
  PackageConfBasePackage_Impl::PackageConfBasePackage_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfBasePackage_Impl
  //
  PackageConfBasePackage_Impl::~PackageConfBasePackage_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfBasePackage_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfBasePackage (this);
  }

  //
  // _create
  //
  PackageConfBasePackage PackageConfBasePackage_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfBasePackage> (parent, PackageConfBasePackage_Impl::metaname);
  }

  //
  // src_PackageConfiguration
  //
  PackageConfiguration PackageConfBasePackage_Impl::src_PackageConfiguration (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return PackageConfiguration::_narrow (target);
  }

  //
  // dst_ComponentPackage
  //
  ComponentPackage PackageConfBasePackage_Impl::dst_ComponentPackage (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentPackage::_narrow (target);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfBasePackage_Impl::parent_PackageConfigurationContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurationContainer> (this->object_.p);
  }
}

