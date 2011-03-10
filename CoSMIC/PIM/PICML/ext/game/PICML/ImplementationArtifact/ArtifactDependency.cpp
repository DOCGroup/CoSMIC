// $Id$

#include "stdafx.h"
#include "ArtifactDependency.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactDependency_Impl::metaname = "ArtifactDependency";

  //
  // ArtifactDependency_Impl
  //
  ArtifactDependency_Impl::ArtifactDependency_Impl (void)
  {
  }

  //
  // ArtifactDependency_Impl
  //
  ArtifactDependency_Impl::ArtifactDependency_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArtifactDependency_Impl
  //
  ArtifactDependency_Impl::~ArtifactDependency_Impl (void)
  {
  }

  //
  // accept
  //
  void ArtifactDependency_Impl::accept (Visitor * v)
  {
    v->visit_ArtifactDependency (this);
  }

  //
  // _create
  //
  ArtifactDependency ArtifactDependency_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ArtifactDependency> (parent, ArtifactDependency_Impl::metaname);
  }

  //
  // src_ImplementationArtifact
  //
  ImplementationArtifact ArtifactDependency_Impl::src_ImplementationArtifact (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ImplementationArtifact::_narrow (target);
  }

  //
  // dst_ImplementationArtifact
  //
  ImplementationArtifact ArtifactDependency_Impl::dst_ImplementationArtifact (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ImplementationArtifact::_narrow (target);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactDependency_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }
}

