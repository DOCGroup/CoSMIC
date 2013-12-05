// $Id$

#include "StdAfx.h"
#include "ImplementationContainer.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationContainer_Impl::metaname ("ImplementationContainer");

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
  ::GAME::Mga::Iterator <ConfigProperty> ImplementationContainer_Impl::get_ConfigPropertys (void) const
  {
    return this->children <ConfigProperty> ();
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
  ::GAME::Mga::Iterator <InfoProperty> ImplementationContainer_Impl::get_InfoPropertys (void) const
  {
    return this->children <InfoProperty> ();
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
  ::GAME::Mga::Iterator <ComplexProperty> ImplementationContainer_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

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
  ::GAME::Mga::Iterator <SimpleProperty> ImplementationContainer_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
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
  ::GAME::Mga::Iterator <ImplementationArtifactReference> ImplementationContainer_Impl::get_ImplementationArtifactReferences (void) const
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
  ::GAME::Mga::Iterator <ComponentImplementationArtifact> ImplementationContainer_Impl::get_ComponentImplementationArtifacts (void) const
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
  ::GAME::Mga::Iterator <ComponentServantArtifact> ImplementationContainer_Impl::get_ComponentServantArtifacts (void) const
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
  ::GAME::Mga::Iterator <ImplementationRequirement> ImplementationContainer_Impl::get_ImplementationRequirements (void) const
  {
    return this->children <ImplementationRequirement> ();
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
  ::GAME::Mga::Iterator <MonolithprimaryArtifact> ImplementationContainer_Impl::get_MonolithprimaryArtifacts (void) const
  {
    return this->children <MonolithprimaryArtifact> ();
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
  ::GAME::Mga::Iterator <MonolithExecParameter> ImplementationContainer_Impl::get_MonolithExecParameters (void) const
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
  ::GAME::Mga::Iterator <MonolithDeployRequirement> ImplementationContainer_Impl::get_MonolithDeployRequirements (void) const
  {
    return this->children <MonolithDeployRequirement> ();
  }
}

