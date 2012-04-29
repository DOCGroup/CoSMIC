// $Id$

#include "StdAfx.h"
#include "ArtifactInfoProperty.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactInfoProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactInfoProperty_Impl::metaname ("ArtifactInfoProperty");

  //
  // _create (const ArtifactContainer_in)
  //
  ArtifactInfoProperty ArtifactInfoProperty_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ArtifactInfoProperty > (parent, ArtifactInfoProperty_Impl::metaname);
  }

  //
  // accept
  //
  void ArtifactInfoProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArtifactInfoProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // ImplementationArtifact
  //
  ImplementationArtifact ArtifactInfoProperty_Impl::src_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->src ());
  }

  //
  // Property
  //
  Property ArtifactInfoProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

