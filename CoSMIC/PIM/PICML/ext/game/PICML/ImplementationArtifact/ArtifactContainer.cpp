// $Id$

#include "stdafx.h"
#include "ArtifactContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactDependency.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/Common/Property.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/Common/Requirement.h"
#include "PICML/ImplementationArtifact/ArtifactDeployRequirement.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationArtifact/ImplementationArtifacts.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactContainer_Impl::metaname = "ArtifactContainer";

  //
  // ArtifactContainer_Impl
  //
  ArtifactContainer_Impl::ArtifactContainer_Impl (void)
  {
  }

  //
  // ArtifactContainer_Impl
  //
  ArtifactContainer_Impl::ArtifactContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArtifactContainer_Impl
  //
  ArtifactContainer_Impl::~ArtifactContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void ArtifactContainer_Impl::accept (Visitor * v)
  {
    v->visit_ArtifactContainer (this);
  }

  //
  // _create
  //
  ArtifactContainer ArtifactContainer_Impl::_create (const ImplementationArtifacts_in parent)
  {
    return ::GAME::Mga::create_root_object <ArtifactContainer> (parent, ArtifactContainer_Impl::metaname);
  }

  //
  // get_ArtifactDependencys
  //
  size_t ArtifactContainer_Impl::get_ArtifactDependencys (std::vector <ArtifactDependency> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactInfoPropertys
  //
  size_t ArtifactContainer_Impl::get_ArtifactInfoPropertys (std::vector <ArtifactInfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactExecParameters
  //
  size_t ArtifactContainer_Impl::get_ArtifactExecParameters (std::vector <ArtifactExecParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t ArtifactContainer_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifacts
  //
  size_t ArtifactContainer_Impl::get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_Requirements
  //
  size_t ArtifactContainer_Impl::get_Requirements (std::vector <Requirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactDeployRequirements
  //
  size_t ArtifactContainer_Impl::get_ArtifactDeployRequirements (std::vector <ArtifactDeployRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifactReferences
  //
  size_t ArtifactContainer_Impl::get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArtifactDependsOns
  //
  size_t ArtifactContainer_Impl::get_ArtifactDependsOns (std::vector <ArtifactDependsOn> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ImplementationArtifacts
  //
  ImplementationArtifacts ArtifactContainer_Impl::parent_ImplementationArtifacts (void) const
  {
    return ::GAME::Mga::get_parent <ImplementationArtifacts> (this->object_.p);
  }
}

