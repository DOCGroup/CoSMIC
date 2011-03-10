// $Id$

#include "stdafx.h"
#include "ArtifactDeployRequirement.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/Common/Requirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactDeployRequirement_Impl::metaname = "ArtifactDeployRequirement";

  //
  // ArtifactDeployRequirement_Impl
  //
  ArtifactDeployRequirement_Impl::ArtifactDeployRequirement_Impl (void)
  {
  }

  //
  // ArtifactDeployRequirement_Impl
  //
  ArtifactDeployRequirement_Impl::ArtifactDeployRequirement_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArtifactDeployRequirement_Impl
  //
  ArtifactDeployRequirement_Impl::~ArtifactDeployRequirement_Impl (void)
  {
  }

  //
  // accept
  //
  void ArtifactDeployRequirement_Impl::accept (Visitor * v)
  {
    v->visit_ArtifactDeployRequirement (this);
  }

  //
  // _create
  //
  ArtifactDeployRequirement ArtifactDeployRequirement_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ArtifactDeployRequirement> (parent, ArtifactDeployRequirement_Impl::metaname);
  }

  //
  // src_ImplementationArtifact
  //
  ImplementationArtifact ArtifactDeployRequirement_Impl::src_ImplementationArtifact (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ImplementationArtifact::_narrow (target);
  }

  //
  // dst_Requirement
  //
  Requirement ArtifactDeployRequirement_Impl::dst_Requirement (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Requirement::_narrow (target);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactDeployRequirement_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }
}

