// $Id$

#include "stdafx.h"
#include "TopLevelPackageContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackage.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackages.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelPackageContainer_Impl::metaname = "TopLevelPackageContainer";

  //
  // TopLevelPackageContainer_Impl
  //
  TopLevelPackageContainer_Impl::TopLevelPackageContainer_Impl (void)
  {
  }

  //
  // TopLevelPackageContainer_Impl
  //
  TopLevelPackageContainer_Impl::TopLevelPackageContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TopLevelPackageContainer_Impl
  //
  TopLevelPackageContainer_Impl::~TopLevelPackageContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void TopLevelPackageContainer_Impl::accept (Visitor * v)
  {
    v->visit_TopLevelPackageContainer (this);
  }

  //
  // _create
  //
  TopLevelPackageContainer TopLevelPackageContainer_Impl::_create (const TopLevelPackages_in parent)
  {
    return ::GAME::Mga::create_root_object <TopLevelPackageContainer> (parent, TopLevelPackageContainer_Impl::metaname);
  }

  //
  // get_package
  //
  package TopLevelPackageContainer_Impl::get_package (void) const
  {
    // Get the collection of children.
    std::vector <package> items;
    this->children (items);

    return !items.empty () ? items.front () : package ();
  }

  //
  // get_TopLevelPackage
  //
  TopLevelPackage TopLevelPackageContainer_Impl::get_TopLevelPackage (void) const
  {
    // Get the collection of children.
    std::vector <TopLevelPackage> items;
    this->children (items);

    return !items.empty () ? items.front () : TopLevelPackage ();
  }

  //
  // get_PackageConfigurationReference
  //
  PackageConfigurationReference TopLevelPackageContainer_Impl::get_PackageConfigurationReference (void) const
  {
    // Get the collection of children.
    std::vector <PackageConfigurationReference> items;
    this->children (items);

    return !items.empty () ? items.front () : PackageConfigurationReference ();
  }

  //
  // parent_TopLevelPackages
  //
  TopLevelPackages TopLevelPackageContainer_Impl::parent_TopLevelPackages (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelPackages> (this->object_.p);
  }
}

