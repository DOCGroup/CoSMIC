// $Id$

#include "stdafx.h"
#include "ComponentBuild.h"

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
  const std::string ComponentBuild_Impl::metaname = "ComponentBuild";

  //
  // ComponentBuild_Impl
  //
  ComponentBuild_Impl::ComponentBuild_Impl (void)
  {
  }

  //
  // ComponentBuild_Impl
  //
  ComponentBuild_Impl::ComponentBuild_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentBuild_Impl
  //
  ComponentBuild_Impl::~ComponentBuild_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentBuild_Impl::accept (Visitor * v)
  {
    v->visit_ComponentBuild (this);
  }

  //
  // _create
  //
  ComponentBuild ComponentBuild_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentBuild> (parent, ComponentBuild_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ComponentBuild_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

