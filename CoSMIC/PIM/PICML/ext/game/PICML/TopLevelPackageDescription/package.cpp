// $Id$

#include "StdAfx.h"
#include "package.h"

#if !defined (__GAME_INLINE__)
#include "package.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackage.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string package_Impl::metaname ("package");

  //
  // _create (const TopLevelPackageContainer_in)
  //
  package package_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < package > (parent, package_Impl::metaname);
  }

  //
  // accept
  //
  void package_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_package (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // TopLevelPackage
  //
  TopLevelPackage package_Impl::src_TopLevelPackage (void) const
  {
    return TopLevelPackage::_narrow (this->src ());
  }

  //
  // PackageConfigurationReference
  //
  PackageConfigurationReference package_Impl::dst_PackageConfigurationReference (void) const
  {
    return PackageConfigurationReference::_narrow (this->dst ());
  }
}

