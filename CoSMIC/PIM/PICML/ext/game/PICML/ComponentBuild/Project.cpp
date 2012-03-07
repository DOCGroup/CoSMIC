// $Id$

#include "StdAfx.h"
#include "Project.h"

#if !defined (__GAME_INLINE__)
#include "Project.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/ExternalResources.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBuild/ComponentLib.h"
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
  // _create (const MPC_in)
  //
  Project Project_Impl::_create (const MPC_in parent)
  {
    return ::GAME::Mga::create_object < Project > (parent, Project_Impl::metaname);
  }

  //
  // accept
  //
  void Project_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Project (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
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
  ::GAME::Mga::Iterator <ExternalResources> Project_Impl::get_ExternalResourcess (void) const
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
  ::GAME::Mga::Iterator <ExtResourceConn> Project_Impl::get_ExtResourceConns (void) const
  {
    return this->children <ExtResourceConn> ();
  }

  //
  // get_ComponentLibs
  //
  size_t Project_Impl::get_ComponentLibs (std::vector <ComponentLib> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentLibs
  //
  ::GAME::Mga::Iterator <ComponentLib> Project_Impl::get_ComponentLibs (void) const
  {
    return this->children <ComponentLib> ();
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
  ::GAME::Mga::Iterator <ImplementationArtifact> Project_Impl::get_ImplementationArtifacts (void) const
  {
    return this->children <ImplementationArtifact> ();
  }
}

