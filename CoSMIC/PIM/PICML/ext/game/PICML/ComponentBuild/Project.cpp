// $Id$

#include "stdafx.h"
#include "Project.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/MPC.h"
#include "PICML/ComponentBuild/ComponentLib.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBuild/ExternalResources.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Project_Impl::metaname = "Project";

  //
  // Project_Impl
  //
  Project_Impl::Project_Impl (void)
  {
  }

  //
  // Project_Impl
  //
  Project_Impl::Project_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Project_Impl
  //
  Project_Impl::~Project_Impl (void)
  {
  }

  //
  // accept
  //
  void Project_Impl::accept (Visitor * v)
  {
    v->visit_Project (this);
  }

  //
  // _create
  //
  Project Project_Impl::_create (const MPC_in parent)
  {
    return ::GAME::Mga::create_object <Project> (parent, Project_Impl::metaname);
  }

  //
  // get_ComponentLibs
  //
  size_t Project_Impl::get_ComponentLibs (std::vector <ComponentLib> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtResourceConns
  //
  size_t Project_Impl::get_ExtResourceConns (std::vector <ExtResourceConn> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExternalResourcess
  //
  size_t Project_Impl::get_ExternalResourcess (std::vector <ExternalResources> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifacts
  //
  size_t Project_Impl::get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // parent_MPC
  //
  MPC Project_Impl::parent_MPC (void) const
  {
    return ::GAME::Mga::get_parent <MPC> (this->object_.p);
  }
}

