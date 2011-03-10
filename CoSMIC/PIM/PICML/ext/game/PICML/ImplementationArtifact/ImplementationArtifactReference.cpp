// $Id$

#include "stdafx.h"
#include "ImplementationArtifactReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationArtifactReference_Impl::metaname = "ImplementationArtifactReference";

  //
  // ImplementationArtifactReference_Impl
  //
  ImplementationArtifactReference_Impl::ImplementationArtifactReference_Impl (void)
  {
  }

  //
  // ImplementationArtifactReference_Impl
  //
  ImplementationArtifactReference_Impl::ImplementationArtifactReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationArtifactReference_Impl
  //
  ImplementationArtifactReference_Impl::~ImplementationArtifactReference_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationArtifactReference_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationArtifactReference (this);
  }

  //
  // _create
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ImplementationArtifactReference> (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // in_ArtifactDependsOn_connections
  //
  size_t ImplementationArtifactReference_Impl::in_ArtifactDependsOn_connections (std::vector <ArtifactDependsOn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ImplementationArtifactReference_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }

  //
  // refers_to_ImplementationArtifact
  //
  ImplementationArtifact ImplementationArtifactReference_Impl::refers_to_ImplementationArtifact (void) const
  {
    return ::GAME::Mga::get_refers_to <ImplementationArtifact> (this);
  }
}

