// $Id$

#include "stdafx.h"
#include "ImplementationArtifacts.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationArtifacts_Impl::metaname = "ImplementationArtifacts";

  //
  // ImplementationArtifacts_Impl
  //
  ImplementationArtifacts_Impl::ImplementationArtifacts_Impl (void)
  {
  }

  //
  // ImplementationArtifacts_Impl
  //
  ImplementationArtifacts_Impl::ImplementationArtifacts_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationArtifacts_Impl
  //
  ImplementationArtifacts_Impl::~ImplementationArtifacts_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationArtifacts_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationArtifacts (this);
  }

  //
  // _create
  //
  ImplementationArtifacts ImplementationArtifacts_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ImplementationArtifacts> (parent, ImplementationArtifacts_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ImplementationArtifacts_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

