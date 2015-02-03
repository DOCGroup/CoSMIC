// $Id$

#include "StdAfx.h"
#include "PackageConfigurationContainer.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfigurationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/Common/Requirement.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/PackageConfiguration/PackageConfigurations.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigurationContainer_Impl::metaname ("PackageConfigurationContainer");

  //
  // is_abstract
  //
  const bool PackageConfigurationContainer_Impl::is_abstract (0);

  //
  // _create (const PackageConfigurations_in)
  //
  PackageConfigurationContainer PackageConfigurationContainer_Impl::_create (const PackageConfigurations_in parent)
  {
    return ::GAME::Mga::create < PackageConfigurationContainer > (parent, PackageConfigurationContainer_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfigurationContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfigurationContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_PackageConfigurations
  //
  PackageConfigurations PackageConfigurationContainer_Impl::parent_PackageConfigurations (void)
  {
    return PackageConfigurations::_narrow (this->parent ());
  }

  //
  // has_ComponentPackage
  //
  bool PackageConfigurationContainer_Impl::has_ComponentPackage (void) const
  {
    return this->children <ComponentPackage> ().count () == 1;
  }

  //
  // get_ComponentPackage
  //
  ComponentPackage PackageConfigurationContainer_Impl::get_ComponentPackage (void) const
  {
    return this->children <ComponentPackage> ().first ();
  }

  //
  // has_PackageConfBasePackage
  //
  bool PackageConfigurationContainer_Impl::has_PackageConfBasePackage (void) const
  {
    return this->children <PackageConfBasePackage> ().count () == 1;
  }

  //
  // get_PackageConfBasePackage
  //
  PackageConfBasePackage PackageConfigurationContainer_Impl::get_PackageConfBasePackage (void) const
  {
    return this->children <PackageConfBasePackage> ().first ();
  }

  //
  // has_PackageConfReference
  //
  bool PackageConfigurationContainer_Impl::has_PackageConfReference (void) const
  {
    return this->children <PackageConfReference> ().count () == 1;
  }

  //
  // get_PackageConfReference
  //
  PackageConfReference PackageConfigurationContainer_Impl::get_PackageConfReference (void) const
  {
    return this->children <PackageConfReference> ().first ();
  }

  //
  // has_ComponentPackageReference
  //
  bool PackageConfigurationContainer_Impl::has_ComponentPackageReference (void) const
  {
    return this->children <ComponentPackageReference> ().count () == 1;
  }

  //
  // get_ComponentPackageReference
  //
  ComponentPackageReference PackageConfigurationContainer_Impl::get_ComponentPackageReference (void) const
  {
    return this->children <ComponentPackageReference> ().first ();
  }

  //
  // has_PackageConfSpecializedConfig
  //
  bool PackageConfigurationContainer_Impl::has_PackageConfSpecializedConfig (void) const
  {
    return this->children <PackageConfSpecializedConfig> ().count () == 1;
  }

  //
  // get_PackageConfSpecializedConfig
  //
  PackageConfSpecializedConfig PackageConfigurationContainer_Impl::get_PackageConfSpecializedConfig (void) const
  {
    return this->children <PackageConfSpecializedConfig> ().first ();
  }

  //
  // get_ComplexPropertys
  //
  size_t PackageConfigurationContainer_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> PackageConfigurationContainer_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t PackageConfigurationContainer_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> PackageConfigurationContainer_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }

  //
  // get_PackageConfigurations
  //
  size_t PackageConfigurationContainer_Impl::get_PackageConfigurations (std::vector <PackageConfiguration> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageConfigurations
  //
  ::GAME::Mga::Collection_T <PackageConfiguration> PackageConfigurationContainer_Impl::get_PackageConfigurations (void) const
  {
    return this->children <PackageConfiguration> ();
  }

  //
  // get_Requirements
  //
  size_t PackageConfigurationContainer_Impl::get_Requirements (std::vector <Requirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_Requirements
  //
  ::GAME::Mga::Collection_T <Requirement> PackageConfigurationContainer_Impl::get_Requirements (void) const
  {
    return this->children <Requirement> ();
  }

  //
  // get_RTRequirementss
  //
  size_t PackageConfigurationContainer_Impl::get_RTRequirementss (std::vector <RTRequirements> & items) const
  {
    return this->children (items);
  }

  //
  // get_RTRequirementss
  //
  ::GAME::Mga::Collection_T <RTRequirements> PackageConfigurationContainer_Impl::get_RTRequirementss (void) const
  {
    return this->children <RTRequirements> ();
  }

  //
  // get_ECRequirementss
  //
  size_t PackageConfigurationContainer_Impl::get_ECRequirementss (std::vector <ECRequirements> & items) const
  {
    return this->children (items);
  }

  //
  // get_ECRequirementss
  //
  ::GAME::Mga::Collection_T <ECRequirements> PackageConfigurationContainer_Impl::get_ECRequirementss (void) const
  {
    return this->children <ECRequirements> ();
  }

  //
  // get_PackageConfSelectRequirements
  //
  size_t PackageConfigurationContainer_Impl::get_PackageConfSelectRequirements (std::vector <PackageConfSelectRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageConfSelectRequirements
  //
  ::GAME::Mga::Collection_T <PackageConfSelectRequirement> PackageConfigurationContainer_Impl::get_PackageConfSelectRequirements (void) const
  {
    return this->children <PackageConfSelectRequirement> ();
  }

  //
  // get_PackageConfConfigPropertys
  //
  size_t PackageConfigurationContainer_Impl::get_PackageConfConfigPropertys (std::vector <PackageConfConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageConfConfigPropertys
  //
  ::GAME::Mga::Collection_T <PackageConfConfigProperty> PackageConfigurationContainer_Impl::get_PackageConfConfigPropertys (void) const
  {
    return this->children <PackageConfConfigProperty> ();
  }
}

