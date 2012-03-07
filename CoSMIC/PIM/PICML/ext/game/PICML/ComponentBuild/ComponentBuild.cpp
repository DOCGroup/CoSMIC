// $Id$

#include "StdAfx.h"
#include "ComponentBuild.h"

#if !defined (__GAME_INLINE__)
#include "ComponentBuild.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/MPC.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentBuild_Impl::metaname ("ComponentBuild");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentBuild ComponentBuild_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentBuild> (parent, ComponentBuild_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentBuild_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentBuild (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_MPCs
  //
  size_t ComponentBuild_Impl::get_MPCs (std::vector <MPC> & items) const
  {
    return this->children (items);
  }
}

