// $Id$

#include "StdAfx.h"
#include "PackageConfigurationReference.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfigurationReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigurationReference_Impl::metaname ("PackageConfigurationReference");

  //
  // _create (const TopLevelPackageContainer_in)
  //
  PackageConfigurationReference PackageConfigurationReference_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfigurationReference > (parent, PackageConfigurationReference_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfigurationReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageConfigurationReference (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // dst_package
  //
  size_t PackageConfigurationReference_Impl::dst_package (std::vector <package> & items) const
  {
    return this->in_connections <package> (items);
  }

  //
  // dst_PackageConfSpecializedConfig
  //
  size_t PackageConfigurationReference_Impl::dst_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const
  {
    return this->in_connections <PackageConfSpecializedConfig> (items);
  }

  //
  // PackageConfiguration_is_nil
  //
  bool PackageConfigurationReference_Impl::PackageConfiguration_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_PackageConfiguration
  //
  PackageConfiguration PackageConfigurationReference_Impl::get_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->refers_to ());
  }
}

