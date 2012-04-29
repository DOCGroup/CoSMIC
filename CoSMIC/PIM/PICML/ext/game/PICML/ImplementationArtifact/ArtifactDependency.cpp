// $Id$

#include "StdAfx.h"
#include "ArtifactDependency.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactDependency.inl"
#endif

#include "PICML/Visitor.h"
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
  const std::string ArtifactDependency_Impl::metaname ("ArtifactDependency");

  //
  // _create (const ArtifactContainer_in)
  //
  ArtifactDependency ArtifactDependency_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ArtifactDependency > (parent, ArtifactDependency_Impl::metaname);
  }

  //
  // accept
  //
  void ArtifactDependency_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ArtifactDependency (this);
    else
      v->visit_Connection (this);
  }

  //
  // ImplementationArtifact
  //
  ImplementationArtifact ArtifactDependency_Impl::src_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->src ());
  }

  //
  // ImplementationArtifact
  //
  ImplementationArtifact ArtifactDependency_Impl::dst_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->dst ());
  }
}

