#include "StdAfx.h"
#include "Project.h"

#if !defined (__GAME_INLINE__)
#include "Project.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/ComponentLib.h"
#include "PICML/ComponentBuild/ExecutorProject.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/ComponentBuild/StubProject.h"
#include "PICML/ComponentBuild/ExternalResources.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBuild/MPC.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Project_Impl::metaname ("Project");

  //
  // is_abstract
  //
  const bool Project_Impl::is_abstract = false;

  //
  // _create (const MPC_in)
  //
  Project Project_Impl::_create (const MPC_in parent)
  {
    return ::GAME::Mga::create < Project > (parent, Project_Impl::metaname);
  }

  //
  // accept
  //
  void Project_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Project (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_MPC
  //
  MPC Project_Impl::parent_MPC (void)
  {
    return MPC::_narrow (this->parent ());
  }

  //
  // get_ExecutorProjects
  //
  size_t Project_Impl::get_ExecutorProjects (std::vector <ExecutorProject> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExecutorProjects
  //
  ::GAME::Mga::Collection_T <ExecutorProject> Project_Impl::get_ExecutorProjects (void) const
  {
    return this->children <ExecutorProject> ();
  }

  //
  // get_ServantProjects
  //
  size_t Project_Impl::get_ServantProjects (std::vector <ServantProject> & items) const
  {
    return this->children (items);
  }

  //
  // get_ServantProjects
  //
  ::GAME::Mga::Collection_T <ServantProject> Project_Impl::get_ServantProjects (void) const
  {
    return this->children <ServantProject> ();
  }

  //
  // get_StubProjects
  //
  size_t Project_Impl::get_StubProjects (std::vector <StubProject> & items) const
  {
    return this->children (items);
  }

  //
  // get_StubProjects
  //
  ::GAME::Mga::Collection_T <StubProject> Project_Impl::get_StubProjects (void) const
  {
    return this->children <StubProject> ();
  }

  //
  // get_ExternalResourcess
  //
  size_t Project_Impl::get_ExternalResourcess (std::vector <ExternalResources> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExternalResourcess
  //
  ::GAME::Mga::Collection_T <ExternalResources> Project_Impl::get_ExternalResourcess (void) const
  {
    return this->children <ExternalResources> ();
  }

  //
  // get_ExtResourceConns
  //
  size_t Project_Impl::get_ExtResourceConns (std::vector <ExtResourceConn> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtResourceConns
  //
  ::GAME::Mga::Collection_T <ExtResourceConn> Project_Impl::get_ExtResourceConns (void) const
  {
    return this->children <ExtResourceConn> ();
  }

  //
  // get_ImplementationArtifacts
  //
  size_t Project_Impl::get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifacts
  //
  ::GAME::Mga::Collection_T <ImplementationArtifact> Project_Impl::get_ImplementationArtifacts (void) const
  {
    return this->children <ImplementationArtifact> ();
  }
}

