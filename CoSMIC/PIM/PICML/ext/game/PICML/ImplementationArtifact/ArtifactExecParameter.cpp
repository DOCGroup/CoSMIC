// $Id$

#include "StdAfx.h"
#include "ArtifactExecParameter.h"

#if !defined (__GAME_INLINE__)
#include "ArtifactExecParameter.inl"
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
  const std::string ArtifactExecParameter_Impl::metaname ("ArtifactExecParameter");

  //
  // _create (const ArtifactContainer_in)
  //
  ArtifactExecParameter ArtifactExecParameter_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ArtifactExecParameter > (parent, ArtifactExecParameter_Impl::metaname);
  }

  //
  // accept
  //
  void ArtifactExecParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ArtifactExecParameter (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

