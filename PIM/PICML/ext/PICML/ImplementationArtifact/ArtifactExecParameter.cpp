// $Id$

#include "StdAfx.h"
#include "ArtifactExecParameter.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactExecParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactExecParameter_Impl::metaname ("ArtifactExecParameter");

  //
  // is_abstract
  //
  const bool ArtifactExecParameter_Impl::is_abstract = false;

  //
  // _create (const ArtifactContainer_in, ImplementationArtifact_in src, Property_in dst)
  //
  ArtifactExecParameter ArtifactExecParameter_Impl::_create (const ArtifactContainer_in parent, ImplementationArtifact_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ArtifactExecParameter_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void ArtifactExecParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArtifactExecParameter (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactExecParameter_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // ImplementationArtifact
  //
  ImplementationArtifact ArtifactExecParameter_Impl::src_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->src ());
  }

  //
  // Property
  //
  Property ArtifactExecParameter_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

