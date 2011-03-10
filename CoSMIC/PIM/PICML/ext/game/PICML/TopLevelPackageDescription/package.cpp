// $Id$

#include "stdafx.h"
#include "package.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackage.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string package_Impl::metaname = "package";

  //
  // package_Impl
  //
  package_Impl::package_Impl (void)
  {
  }

  //
  // package_Impl
  //
  package_Impl::package_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~package_Impl
  //
  package_Impl::~package_Impl (void)
  {
  }

  //
  // accept
  //
  void package_Impl::accept (Visitor * v)
  {
    v->visit_package (this);
  }

  //
  // _create
  //
  package package_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <package> (parent, package_Impl::metaname);
  }

  //
  // src_TopLevelPackage
  //
  TopLevelPackage package_Impl::src_TopLevelPackage (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return TopLevelPackage::_narrow (target);
  }

  //
  // dst_PackageConfigurationReference
  //
  PackageConfigurationReference package_Impl::dst_PackageConfigurationReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return PackageConfigurationReference::_narrow (target);
  }

  //
  // parent_TopLevelPackageContainer
  //
  TopLevelPackageContainer package_Impl::parent_TopLevelPackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelPackageContainer> (this->object_.p);
  }
}

