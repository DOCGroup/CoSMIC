// $Id$

#include "stdafx.h"
#include "PackageConfigurationContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/Requirement.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "PICML/PackageConfiguration/PackageConfigurations.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigurationContainer_Impl::metaname = "PackageConfigurationContainer";

  //
  // PackageConfigurationContainer_Impl
  //
  PackageConfigurationContainer_Impl::PackageConfigurationContainer_Impl (void)
  {
  }

  //
  // PackageConfigurationContainer_Impl
  //
  PackageConfigurationContainer_Impl::PackageConfigurationContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfigurationContainer_Impl
  //
  PackageConfigurationContainer_Impl::~PackageConfigurationContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfigurationContainer_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfigurationContainer (this);
  }

  //
  // _create
  //
  PackageConfigurationContainer PackageConfigurationContainer_Impl::_create (const PackageConfigurations_in parent)
  {
    return ::GAME::Mga::create_root_object <PackageConfigurationContainer> (parent, PackageConfigurationContainer_Impl::metaname);
  }

  //
  // get_PackageConfigurations
  //
  size_t PackageConfigurationContainer_Impl::get_PackageConfigurations (std::vector <PackageConfiguration> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageConfSpecializedConfig
  //
  PackageConfSpecializedConfig PackageConfigurationContainer_Impl::get_PackageConfSpecializedConfig (void) const
  {
    // Get the collection of children.
    std::vector <PackageConfSpecializedConfig> items;
    this->children (items);

    return !items.empty () ? items.front () : PackageConfSpecializedConfig ();
  }

  //
  // get_PackageConfSelectRequirements
  //
  size_t PackageConfigurationContainer_Impl::get_PackageConfSelectRequirements (std::vector <PackageConfSelectRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageConfConfigPropertys
  //
  size_t PackageConfigurationContainer_Impl::get_PackageConfConfigPropertys (std::vector <PackageConfConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t PackageConfigurationContainer_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Requirements
  //
  size_t PackageConfigurationContainer_Impl::get_Requirements (std::vector <Requirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPackageReference
  //
  ComponentPackageReference PackageConfigurationContainer_Impl::get_ComponentPackageReference (void) const
  {
    // Get the collection of children.
    std::vector <ComponentPackageReference> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentPackageReference ();
  }

  //
  // get_ComponentPackage
  //
  ComponentPackage PackageConfigurationContainer_Impl::get_ComponentPackage (void) const
  {
    // Get the collection of children.
    std::vector <ComponentPackage> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentPackage ();
  }

  //
  // get_PackageConfReference
  //
  PackageConfReference PackageConfigurationContainer_Impl::get_PackageConfReference (void) const
  {
    // Get the collection of children.
    std::vector <PackageConfReference> items;
    this->children (items);

    return !items.empty () ? items.front () : PackageConfReference ();
  }

  //
  // get_PackageConfBasePackage
  //
  PackageConfBasePackage PackageConfigurationContainer_Impl::get_PackageConfBasePackage (void) const
  {
    // Get the collection of children.
    std::vector <PackageConfBasePackage> items;
    this->children (items);

    return !items.empty () ? items.front () : PackageConfBasePackage ();
  }

  //
  // parent_PackageConfigurations
  //
  PackageConfigurations PackageConfigurationContainer_Impl::parent_PackageConfigurations (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurations> (this->object_.p);
  }
}

