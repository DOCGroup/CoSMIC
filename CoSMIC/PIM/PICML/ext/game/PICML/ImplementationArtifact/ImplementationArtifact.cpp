// $Id$

#include "StdAfx.h"
#include "ImplementationArtifact.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationArtifact.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationArtifact/ArtifactDeployRequirement.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/ImplementationArtifact/ArtifactDependency.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationArtifact_Impl::metaname ("ImplementationArtifact");

  //
  // _create (const Project_in)
  //
  ImplementationArtifact ImplementationArtifact_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifact > (parent, ImplementationArtifact_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  ImplementationArtifact ImplementationArtifact_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifact > (parent, ImplementationArtifact_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationArtifact_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ImplementationArtifact (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // src_ArtifactDependsOn
  //
  size_t ImplementationArtifact_Impl::src_ArtifactDependsOn (std::vector <ArtifactDependsOn> & items) const
  {
    return this->in_connections <ArtifactDependsOn> (items);
  }

  //
  // src_ArtifactDeployRequirement
  //
  size_t ImplementationArtifact_Impl::src_ArtifactDeployRequirement (std::vector <ArtifactDeployRequirement> & items) const
  {
    return this->in_connections <ArtifactDeployRequirement> (items);
  }

  //
  // src_ArtifactExecParameter
  //
  size_t ImplementationArtifact_Impl::src_ArtifactExecParameter (std::vector <ArtifactExecParameter> & items) const
  {
    return this->in_connections <ArtifactExecParameter> (items);
  }

  //
  // src_ArtifactInfoProperty
  //
  size_t ImplementationArtifact_Impl::src_ArtifactInfoProperty (std::vector <ArtifactInfoProperty> & items) const
  {
    return this->in_connections <ArtifactInfoProperty> (items);
  }

  //
  // src_ArtifactDependency
  //
  size_t ImplementationArtifact_Impl::src_ArtifactDependency (std::vector <ArtifactDependency> & items) const
  {
    return this->in_connections <ArtifactDependency> (items);
  }

  //
  // dst_ArtifactDependency
  //
  size_t ImplementationArtifact_Impl::dst_ArtifactDependency (std::vector <ArtifactDependency> & items) const
  {
    return this->in_connections <ArtifactDependency> (items);
  }
}

