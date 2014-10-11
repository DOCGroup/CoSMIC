// $Id$

#include "StdAfx.h"
#include "MPC.h"

#if !defined (__GAME_INLINE__)
#include "MPC.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ComponentBuild.h"
#include "PICML/ComponentBuild/Workspaces.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MPC_Impl::metaname ("MPC");

  //
  // _create (const ComponentBuild_in)
  //
  MPC MPC_Impl::_create (const ComponentBuild_in parent)
  {
    return ::GAME::Mga::create_root_object < MPC > (parent, MPC_Impl::metaname);
  }

  //
  // accept
  //
  void MPC_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MPC (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentBuild
  //
  ComponentBuild MPC_Impl::parent_ComponentBuild (void)
  {
    return ComponentBuild::_narrow (this->parent ());
  }

  //
  // get_Projects
  //
  size_t MPC_Impl::get_Projects (std::vector <Project> & items) const
  {
    return this->children (items);
  }

  //
  // get_Projects
  //
  ::GAME::Mga::Collection_T <Project> MPC_Impl::get_Projects (void) const
  {
    return this->children <Project> ();
  }

  //
  // get_Workspacess
  //
  size_t MPC_Impl::get_Workspacess (std::vector <Workspaces> & items) const
  {
    return this->children (items);
  }

  //
  // get_Workspacess
  //
  ::GAME::Mga::Collection_T <Workspaces> MPC_Impl::get_Workspacess (void) const
  {
    return this->children <Workspaces> ();
  }
}

