// $Id$

#include "StdAfx.h"
#include "ArtifactContainer.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/Common/Requirement.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/ImplementationArtifact/ArtifactDeployRequirement.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationArtifact/ArtifactDependency.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationArtifact/ImplementationArtifacts.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactContainer_Impl::metaname ("ArtifactContainer");

  //
  // _create (const ImplementationArtifacts_in)
  //
  ArtifactContainer ArtifactContainer_Impl::_create (const ImplementationArtifacts_in parent)
  {
    return ::GAME::Mga::create_root_object < ArtifactContainer > (parent, ArtifactContainer_Impl::metaname);
  }

  //
  // accept
  //
  void ArtifactContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArtifactContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ImplementationArtifacts
  //
  ImplementationArtifacts ArtifactContainer_Impl::parent_ImplementationArtifacts (void)
  {
    return ImplementationArtifacts::_narrow (this->parent ());
  }

  //
  // get_ComplexPropertys
  //
  size_t ArtifactContainer_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Iterator <ComplexProperty> ArtifactContainer_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t ArtifactContainer_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Iterator <SimpleProperty> ArtifactContainer_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }

  //
  // get_ImplementationArtifactReferences
  //
  size_t ArtifactContainer_Impl::get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifactReferences
  //
  ::GAME::Mga::Iterator <ImplementationArtifactReference> ArtifactContainer_Impl::get_ImplementationArtifactReferences (void) const
  {
    return this->children <ImplementationArtifactReference> ();
  }

  //
  // get_ComponentImplementationArtifacts
  //
  size_t ArtifactContainer_Impl::get_ComponentImplementationArtifacts (std::vector <ComponentImplementationArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentImplementationArtifacts
  //
  ::GAME::Mga::Iterator <ComponentImplementationArtifact> ArtifactContainer_Impl::get_ComponentImplementationArtifacts (void) const
  {
    return this->children <ComponentImplementationArtifact> ();
  }

  //
  // get_ComponentServantArtifacts
  //
  size_t ArtifactContainer_Impl::get_ComponentServantArtifacts (std::vector <ComponentServantArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentServantArtifacts
  //
  ::GAME::Mga::Iterator <ComponentServantArtifact> ArtifactContainer_Impl::get_ComponentServantArtifacts (void) const
  {
    return this->children <ComponentServantArtifact> ();
  }

  //
  // get_Requirements
  //
  size_t ArtifactContainer_Impl::get_Requirements (std::vector <Requirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_Requirements
  //
  ::GAME::Mga::Iterator <Requirement> ArtifactContainer_Impl::get_Requirements (void) const
  {
    return this->children <Requirement> ();
  }

  //
  // get_RTRequirementss
  //
  size_t ArtifactContainer_Impl::get_RTRequirementss (std::vector <RTRequirements> & items) const
  {
    return this->children (items);
  }

  //
  // get_RTRequirementss
  //
  ::GAME::Mga::Iterator <RTRequirements> ArtifactContainer_Impl::get_RTRequirementss (void) const
  {
    return this->children <RTRequirements> ();
  }

  //
  // get_ECRequirementss
  //
  size_t ArtifactContainer_Impl::get_ECRequirementss (std::vector <ECRequirements> & items) const
  {
    return this->children (items);
  }

  //
  // get_ECRequirementss
  //
  ::GAME::Mga::Iterator <ECRequirements> ArtifactContainer_Impl::get_ECRequirementss (void) const
  {
    return this->children <ECRequirements> ();
  }

  //
  // get_ArtifactDeployRequirements
  //
  size_t ArtifactContainer_Impl::get_ArtifactDeployRequirements (std::vector <ArtifactDeployRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactDeployRequirements
  //
  ::GAME::Mga::Iterator <ArtifactDeployRequirement> ArtifactContainer_Impl::get_ArtifactDeployRequirements (void) const
  {
    return this->children <ArtifactDeployRequirement> ();
  }

  //
  // get_ImplementationArtifacts
  //
  size_t ArtifactContainer_Impl::get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifacts
  //
  ::GAME::Mga::Iterator <ImplementationArtifact> ArtifactContainer_Impl::get_ImplementationArtifacts (void) const
  {
    return this->children <ImplementationArtifact> ();
  }

  //
  // get_ArtifactDependencys
  //
  size_t ArtifactContainer_Impl::get_ArtifactDependencys (std::vector <ArtifactDependency> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactDependencys
  //
  ::GAME::Mga::Iterator <ArtifactDependency> ArtifactContainer_Impl::get_ArtifactDependencys (void) const
  {
    return this->children <ArtifactDependency> ();
  }

  //
  // get_ArtifactInfoPropertys
  //
  size_t ArtifactContainer_Impl::get_ArtifactInfoPropertys (std::vector <ArtifactInfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactInfoPropertys
  //
  ::GAME::Mga::Iterator <ArtifactInfoProperty> ArtifactContainer_Impl::get_ArtifactInfoPropertys (void) const
  {
    return this->children <ArtifactInfoProperty> ();
  }

  //
  // get_ArtifactExecParameters
  //
  size_t ArtifactContainer_Impl::get_ArtifactExecParameters (std::vector <ArtifactExecParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactExecParameters
  //
  ::GAME::Mga::Iterator <ArtifactExecParameter> ArtifactContainer_Impl::get_ArtifactExecParameters (void) const
  {
    return this->children <ArtifactExecParameter> ();
  }

  //
  // get_ArtifactDependsOns
  //
  size_t ArtifactContainer_Impl::get_ArtifactDependsOns (std::vector <ArtifactDependsOn> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactDependsOns
  //
  ::GAME::Mga::Iterator <ArtifactDependsOn> ArtifactContainer_Impl::get_ArtifactDependsOns (void) const
  {
    return this->children <ArtifactDependsOn> ();
  }
}
