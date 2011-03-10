// $Id$

#include "stdafx.h"
#include "ArtifactInfoProperty.h"

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
  const std::string ArtifactInfoProperty_Impl::metaname = "ArtifactInfoProperty";

  //
  // ArtifactInfoProperty_Impl
  //
  ArtifactInfoProperty_Impl::ArtifactInfoProperty_Impl (void)
  {
  }

  //
  // ArtifactInfoProperty_Impl
  //
  ArtifactInfoProperty_Impl::ArtifactInfoProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArtifactInfoProperty_Impl
  //
  ArtifactInfoProperty_Impl::~ArtifactInfoProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void ArtifactInfoProperty_Impl::accept (Visitor * v)
  {
    v->visit_ArtifactInfoProperty (this);
  }

  //
  // _create
  //
  ArtifactInfoProperty ArtifactInfoProperty_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ArtifactInfoProperty> (parent, ArtifactInfoProperty_Impl::metaname);
  }

  //
  // src_ImplementationArtifact
  //
  ImplementationArtifact ArtifactInfoProperty_Impl::src_ImplementationArtifact (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ImplementationArtifact::_narrow (target);
  }

  //
  // dst_Property
  //
  Property ArtifactInfoProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactInfoProperty_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }
}

