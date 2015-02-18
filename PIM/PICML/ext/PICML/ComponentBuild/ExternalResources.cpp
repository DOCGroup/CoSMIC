// $Id$

#include "StdAfx.h"
#include "ExternalResources.h"

#if !defined (__GAME_INLINE__)
#include "ExternalResources.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBuild/Project.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalResources_Impl::metaname ("ExternalResources");

  //
  // is_abstract
  //
  const bool ExternalResources_Impl::is_abstract = false;

  //
  // _create (const Project_in)
  //
  ExternalResources ExternalResources_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create < ExternalResources > (parent, ExternalResources_Impl::metaname);
  }

  //
  // accept
  //
  void ExternalResources_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExternalResources (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Project
  //
  Project ExternalResources_Impl::parent_Project (void)
  {
    return Project::_narrow (this->parent ());
  }

  //
  // dst_of_ExtResourceConn
  //
  size_t ExternalResources_Impl::dst_of_ExtResourceConn (std::vector <ExtResourceConn> & items) const
  {
    return this->in_connections <ExtResourceConn> (items);
  }

  //
  // dst_of_ExtResourceConn
  //
  GAME::Mga::Collection_T <ExtResourceConn> ExternalResources_Impl::dst_of_ExtResourceConn (void) const
  {
    return this->in_connections <ExtResourceConn> ("dst");
  }

  //
  // ImplementationArtifact_is_nil
  //
  bool ExternalResources_Impl::ImplementationArtifact_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ImplementationArtifact
  //
  void ExternalResources_Impl::refers_to_ImplementationArtifact (ImplementationArtifact_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ImplementationArtifact
  //
  ImplementationArtifact ExternalResources_Impl::refers_to_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->refers_to ());
  }
}

