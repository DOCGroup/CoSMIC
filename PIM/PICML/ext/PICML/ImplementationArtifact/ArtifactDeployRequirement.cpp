// $Id$

#include "StdAfx.h"
#include "ArtifactDeployRequirement.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactDeployRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Requirement.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactDeployRequirement_Impl::metaname ("ArtifactDeployRequirement");

  //
  // _create (const ArtifactContainer_in)
  //
  ArtifactDeployRequirement ArtifactDeployRequirement_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ArtifactDeployRequirement > (parent, ArtifactDeployRequirement_Impl::metaname);
  }

  //
  // accept
  //
  void ArtifactDeployRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArtifactDeployRequirement (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactDeployRequirement_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // ImplementationArtifact
  //
  ImplementationArtifact ArtifactDeployRequirement_Impl::src_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->src ());
  }

  //
  // Requirement
  //
  Requirement ArtifactDeployRequirement_Impl::dst_Requirement (void) const
  {
    return Requirement::_narrow (this->dst ());
  }
}

