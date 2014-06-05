// $Id$

#include "StdAfx.h"
#include "ArtifactDependsOn.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactDependsOn.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ArtifactDependsOn_Impl::metaname ("ArtifactDependsOn");

  //
  // _create (const ArtifactContainer_in)
  //
  ArtifactDependsOn ArtifactDependsOn_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ArtifactDependsOn > (parent, ArtifactDependsOn_Impl::metaname);
  }

  //
  // accept
  //
  void ArtifactDependsOn_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArtifactDependsOn (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ArtifactDependsOn_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // ImplementationArtifact
  //
  ImplementationArtifact ArtifactDependsOn_Impl::src_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->src ());
  }

  //
  // ImplementationArtifactReference
  //
  ImplementationArtifactReference ArtifactDependsOn_Impl::dst_ImplementationArtifactReference (void) const
  {
    return ImplementationArtifactReference::_narrow (this->dst ());
  }
}

