// $Id$

#include "stdafx.h"
#include "ExternalResources.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalResources_Impl::metaname = "ExternalResources";

  //
  // ExternalResources_Impl
  //
  ExternalResources_Impl::ExternalResources_Impl (void)
  {
  }

  //
  // ExternalResources_Impl
  //
  ExternalResources_Impl::ExternalResources_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExternalResources_Impl
  //
  ExternalResources_Impl::~ExternalResources_Impl (void)
  {
  }

  //
  // accept
  //
  void ExternalResources_Impl::accept (Visitor * v)
  {
    v->visit_ExternalResources (this);
  }

  //
  // _create
  //
  ExternalResources ExternalResources_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object <ExternalResources> (parent, ExternalResources_Impl::metaname);
  }

  //
  // in_ExtResourceConn_connections
  //
  size_t ExternalResources_Impl::in_ExtResourceConn_connections (std::vector <ExtResourceConn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Project
  //
  Project ExternalResources_Impl::parent_Project (void) const
  {
    return ::GAME::Mga::get_parent <Project> (this->object_.p);
  }
}

