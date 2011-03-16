// $Id$

#include "stdafx.h"
#include "MPC.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Workspaces.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ComponentBuild.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MPC_Impl::metaname = "MPC";

  //
  // MPC_Impl
  //
  MPC_Impl::MPC_Impl (void)
  {
  }

  //
  // MPC_Impl
  //
  MPC_Impl::MPC_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MPC_Impl
  //
  MPC_Impl::~MPC_Impl (void)
  {
  }

  //
  // accept
  //
  void MPC_Impl::accept (Visitor * v)
  {
    v->visit_MPC (this);
  }

  //
  // _create
  //
  MPC MPC_Impl::_create (const ComponentBuild_in parent)
  {
    return ::GAME::Mga::create_root_object <MPC> (parent, MPC_Impl::metaname);
  }

  //
  // get_Workspacess
  //
  size_t MPC_Impl::get_Workspacess (std::vector <Workspaces> & items) const
  {
    return this->children (items);
  }

  //
  // get_Projects
  //
  size_t MPC_Impl::get_Projects (std::vector <Project> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ComponentBuild
  //
  ComponentBuild MPC_Impl::parent_ComponentBuild (void) const
  {
    return ::GAME::Mga::get_parent <ComponentBuild> (this->object_.p);
  }
}

