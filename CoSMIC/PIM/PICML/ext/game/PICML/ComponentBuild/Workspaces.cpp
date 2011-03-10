// $Id$

#include "stdafx.h"
#include "Workspaces.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/MPC.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Workspaces_Impl::metaname = "Workspaces";

  //
  // Workspaces_Impl
  //
  Workspaces_Impl::Workspaces_Impl (void)
  {
  }

  //
  // Workspaces_Impl
  //
  Workspaces_Impl::Workspaces_Impl (IMgaSet * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Workspaces_Impl
  //
  Workspaces_Impl::~Workspaces_Impl (void)
  {
  }

  //
  // accept
  //
  void Workspaces_Impl::accept (Visitor * v)
  {
    v->visit_Workspaces (this);
  }

  //
  // _create
  //
  Workspaces Workspaces_Impl::_create (const MPC_in parent)
  {
    return ::GAME::Mga::create_object <Workspaces> (parent, Workspaces_Impl::metaname);
  }

  //
  // parent_MPC
  //
  MPC Workspaces_Impl::parent_MPC (void) const
  {
    return ::GAME::Mga::get_parent <MPC> (this->object_.p);
  }
}

