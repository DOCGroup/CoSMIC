// $Id$

#include "StdAfx.h"
#include "Workspaces.h"

#if !defined (__GAME_INLINE__)
#include "Workspaces.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/MPC.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Workspaces_Impl::metaname ("Workspaces");

  //
  // _create (const MPC_in)
  //
  Workspaces Workspaces_Impl::_create (const MPC_in parent)
  {
    return ::GAME::Mga::create_object < Workspaces > (parent, Workspaces_Impl::metaname);
  }

  //
  // accept
  //
  void Workspaces_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Workspaces (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Set (this);
    }
  }
}

