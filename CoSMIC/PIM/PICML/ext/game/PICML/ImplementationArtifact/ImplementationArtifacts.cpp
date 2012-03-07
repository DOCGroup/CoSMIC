// $Id$

#include "StdAfx.h"
#include "ImplementationArtifacts.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationArtifacts.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationArtifacts_Impl::metaname ("ImplementationArtifacts");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ImplementationArtifacts ImplementationArtifacts_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ImplementationArtifacts> (parent, ImplementationArtifacts_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationArtifacts_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ImplementationArtifacts (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_ArtifactContainers
  //
  size_t ImplementationArtifacts_Impl::get_ArtifactContainers (std::vector <ArtifactContainer> & items) const
  {
    return this->children (items);
  }
}

