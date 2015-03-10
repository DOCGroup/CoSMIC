// $Id$

#include "StdAfx.h"
#include "PackageConfigurationReference.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfigurationReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
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
  // is_abstract
  //
  const bool PackageConfigurationReference_Impl::is_abstract = false;

  //
  // _create (const TopLevelPackageContainer_in)
  //
  PackageConfigurationReference PackageConfigurationReference_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create < PackageConfigurationReference > (parent, PackageConfigurationReference_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfigurationReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfigurationReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TopLevelPackageContainer
  //
  TopLevelPackageContainer PackageConfigurationReference_Impl::parent_TopLevelPackageContainer (void)
  {
    return TopLevelPackageContainer::_narrow (this->parent ());
  }

  //
  // dst_of_PackageConfSpecializedConfig
  //
  size_t PackageConfigurationReference_Impl::dst_of_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const
  {
    return this->in_connections <PackageConfSpecializedConfig> (items);
  }

  //
  // dst_of_PackageConfSpecializedConfig
  //
  GAME::Mga::Collection_T <PackageConfSpecializedConfig> PackageConfigurationReference_Impl::dst_of_PackageConfSpecializedConfig (void) const
  {
    return this->in_connections <PackageConfSpecializedConfig> ("dst");
  }

  //
  // dst_of_package
  //
  size_t PackageConfigurationReference_Impl::dst_of_package (std::vector <package> & items) const
  {
    return this->in_connections <package> (items);
  }

  //
  // dst_of_package
  //
  package PackageConfigurationReference_Impl::dst_of_package (void) const
  {
    return this->in_connections <package> ("dst").first ();
  }

  //
  // PackageConfiguration_is_nil
  //
  bool PackageConfigurationReference_Impl::PackageConfiguration_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_PackageConfiguration
  //
  void PackageConfigurationReference_Impl::refers_to_PackageConfiguration (PackageConfiguration_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_PackageConfiguration
  //
  PackageConfiguration PackageConfigurationReference_Impl::refers_to_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->refers_to ());
  }
}

