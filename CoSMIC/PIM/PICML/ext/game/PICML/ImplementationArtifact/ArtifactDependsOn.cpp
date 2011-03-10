// $Id$

#include "stdafx.h"
#include "ArtifactDependsOn.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactDependsOn_Impl::metaname = "ArtifactDependsOn";

  //
  // ArtifactDependsOn_Impl
  //
  ArtifactDependsOn_Impl::ArtifactDependsOn_Impl (void)
  {
  }

  //
  // ArtifactDependsOn_Impl
  //
  ArtifactDependsOn_Impl::ArtifactDependsOn_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArtifactDependsOn_Impl
  //
  ArtifactDependsOn_Impl::~ArtifactDependsOn_Impl (void)
  {
  }

  //
  // accept
  //
  void ArtifactDependsOn_Impl::accept (Visitor * v)
  {
    v->visit_ArtifactDependsOn (this);
  }

  //
  // _create
  //
  ArtifactDependsOn ArtifactDependsOn_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ArtifactDependsOn> (parent, ArtifactDependsOn_Impl::metaname);
  }

  //
  // src_ImplementationArtifact
  //
  ImplementationArtifact ArtifactDependsOn_Impl::src_ImplementationArtifact (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ImplementationArtifact::_narrow (target);
  }

  //
  // dst_ImplementationArtifactReference
  //
  ImplementationArtifactReference ArtifactDependsOn_Impl::dst_ImplementationArtifactReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ImplementationArtifactReference::_narrow (target);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactDependsOn_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }
}

