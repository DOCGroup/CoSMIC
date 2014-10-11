// $Id$

#include "StdAfx.h"
#include "TopLevelPackageContainer.h"

#if !defined (__GAME_INLINE__)
#include "TopLevelPackageContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackage.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackages.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelPackageContainer_Impl::metaname ("TopLevelPackageContainer");

  //
  // _create (const TopLevelPackages_in)
  //
  TopLevelPackageContainer TopLevelPackageContainer_Impl::_create (const TopLevelPackages_in parent)
  {
    return ::GAME::Mga::create_root_object < TopLevelPackageContainer > (parent, TopLevelPackageContainer_Impl::metaname);
  }

  //
  // accept
  //
  void TopLevelPackageContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopLevelPackageContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_TopLevelPackages
  //
  TopLevelPackages TopLevelPackageContainer_Impl::parent_TopLevelPackages (void)
  {
    return TopLevelPackages::_narrow (this->parent ());
  }

  //
  // has_PackageConfigurationReference
  //
  bool TopLevelPackageContainer_Impl::has_PackageConfigurationReference (void) const
  {
    return this->children <PackageConfigurationReference> ().count () == 1;
  }

  //
  // get_PackageConfigurationReference
  //
  PackageConfigurationReference TopLevelPackageContainer_Impl::get_PackageConfigurationReference (void) const
  {
    return this->children <PackageConfigurationReference> ().first ();
  }

  //
  // has_package
  //
  bool TopLevelPackageContainer_Impl::has_package (void) const
  {
    return this->children <package> ().count () == 1;
  }

  //
  // get_package
  //
  package TopLevelPackageContainer_Impl::get_package (void) const
  {
    return this->children <package> ().first ();
  }

  //
  // has_TopLevelPackage
  //
  bool TopLevelPackageContainer_Impl::has_TopLevelPackage (void) const
  {
    return this->children <TopLevelPackage> ().count () == 1;
  }

  //
  // get_TopLevelPackage
  //
  TopLevelPackage TopLevelPackageContainer_Impl::get_TopLevelPackage (void) const
  {
    return this->children <TopLevelPackage> ().first ();
  }
}

