// $Id$

#include "StdAfx.h"
#include "ImplementationContainer.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/ImplementationCommon/InfoProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationContainer_Impl::metaname ("ImplementationContainer");

  //
  // is_abstract
  //
  const bool ImplementationContainer_Impl::is_abstract = true;

  //
  // get_SimplePropertys
  //
  size_t ImplementationContainer_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> ImplementationContainer_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t ImplementationContainer_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> ImplementationContainer_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_ConfigPropertys
  //
  size_t ImplementationContainer_Impl::get_ConfigPropertys (std::vector <ConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConfigPropertys
  //
  ::GAME::Mga::Collection_T <ConfigProperty> ImplementationContainer_Impl::get_ConfigPropertys (void) const
  {
    return this->children <ConfigProperty> ();
  }

  //
  // get_MonolithExecParameters
  //
  size_t ImplementationContainer_Impl::get_MonolithExecParameters (std::vector <MonolithExecParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_MonolithExecParameters
  //
  ::GAME::Mga::Collection_T <MonolithExecParameter> ImplementationContainer_Impl::get_MonolithExecParameters (void) const
  {
    return this->children <MonolithExecParameter> ();
  }

  //
  // get_MonolithDeployRequirements
  //
  size_t ImplementationContainer_Impl::get_MonolithDeployRequirements (std::vector <MonolithDeployRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_MonolithDeployRequirements
  //
  ::GAME::Mga::Collection_T <MonolithDeployRequirement> ImplementationContainer_Impl::get_MonolithDeployRequirements (void) const
  {
    return this->children <MonolithDeployRequirement> ();
  }

  //
  // get_MonolithprimaryArtifacts
  //
  size_t ImplementationContainer_Impl::get_MonolithprimaryArtifacts (std::vector <MonolithprimaryArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_MonolithprimaryArtifacts
  //
  ::GAME::Mga::Collection_T <MonolithprimaryArtifact> ImplementationContainer_Impl::get_MonolithprimaryArtifacts (void) const
  {
    return this->children <MonolithprimaryArtifact> ();
  }

  //
  // get_ImplementationArtifactReferences
  //
  size_t ImplementationContainer_Impl::get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifactReferences
  //
  ::GAME::Mga::Collection_T <ImplementationArtifactReference> ImplementationContainer_Impl::get_ImplementationArtifactReferences (void) const
  {
    return this->children <ImplementationArtifactReference> ();
  }

  //
  // get_ComponentImplementationArtifacts
  //
  size_t ImplementationContainer_Impl::get_ComponentImplementationArtifacts (std::vector <ComponentImplementationArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentImplementationArtifacts
  //
  ::GAME::Mga::Collection_T <ComponentImplementationArtifact> ImplementationContainer_Impl::get_ComponentImplementationArtifacts (void) const
  {
    return this->children <ComponentImplementationArtifact> ();
  }

  //
  // get_ComponentServantArtifacts
  //
  size_t ImplementationContainer_Impl::get_ComponentServantArtifacts (std::vector <ComponentServantArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentServantArtifacts
  //
  ::GAME::Mga::Collection_T <ComponentServantArtifact> ImplementationContainer_Impl::get_ComponentServantArtifacts (void) const
  {
    return this->children <ComponentServantArtifact> ();
  }

  //
  // get_ImplementationRequirements
  //
  size_t ImplementationContainer_Impl::get_ImplementationRequirements (std::vector <ImplementationRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationRequirements
  //
  ::GAME::Mga::Collection_T <ImplementationRequirement> ImplementationContainer_Impl::get_ImplementationRequirements (void) const
  {
    return this->children <ImplementationRequirement> ();
  }

  //
  // get_InfoPropertys
  //
  size_t ImplementationContainer_Impl::get_InfoPropertys (std::vector <InfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_InfoPropertys
  //
  ::GAME::Mga::Collection_T <InfoProperty> ImplementationContainer_Impl::get_InfoPropertys (void) const
  {
    return this->children <InfoProperty> ();
  }
}

