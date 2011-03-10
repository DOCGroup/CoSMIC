// $Id$

#include "stdafx.h"
#include "ArtifactExecParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactExecParameter_Impl::metaname = "ArtifactExecParameter";

  //
  // ArtifactExecParameter_Impl
  //
  ArtifactExecParameter_Impl::ArtifactExecParameter_Impl (void)
  {
  }

  //
  // ArtifactExecParameter_Impl
  //
  ArtifactExecParameter_Impl::ArtifactExecParameter_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArtifactExecParameter_Impl
  //
  ArtifactExecParameter_Impl::~ArtifactExecParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void ArtifactExecParameter_Impl::accept (Visitor * v)
  {
    v->visit_ArtifactExecParameter (this);
  }

  //
  // _create
  //
  ArtifactExecParameter ArtifactExecParameter_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ArtifactExecParameter> (parent, ArtifactExecParameter_Impl::metaname);
  }

  //
  // src_ImplementationArtifact
  //
  ImplementationArtifact ArtifactExecParameter_Impl::src_ImplementationArtifact (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ImplementationArtifact::_narrow (target);
  }

  //
  // dst_Property
  //
  Property ArtifactExecParameter_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactExecParameter_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }
}

