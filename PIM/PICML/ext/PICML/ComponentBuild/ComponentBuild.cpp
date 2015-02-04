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
  // is_abstract
  //
  const bool ComponentBuild_Impl::is_abstract = false;

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentBuild ComponentBuild_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <ComponentBuild> (parent, ComponentBuild_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentBuild_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentBuild (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder ComponentBuild_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_MPCs
  //
  size_t ComponentBuild_Impl::get_MPCs (std::vector <MPC> & items) const
  {
    return this->children (items);
  }

  //
  // get_MPCs
  //
  ::GAME::Mga::Collection_T <MPC> ComponentBuild_Impl::get_MPCs (void) const
  {
    return this->children <MPC> ();
  }
}

