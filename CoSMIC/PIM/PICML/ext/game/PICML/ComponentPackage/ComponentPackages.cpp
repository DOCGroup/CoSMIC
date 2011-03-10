// $Id$

#include "stdafx.h"
#include "ComponentPackages.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPackages_Impl::metaname = "ComponentPackages";

  //
  // ComponentPackages_Impl
  //
  ComponentPackages_Impl::ComponentPackages_Impl (void)
  {
  }

  //
  // ComponentPackages_Impl
  //
  ComponentPackages_Impl::ComponentPackages_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentPackages_Impl
  //
  ComponentPackages_Impl::~ComponentPackages_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentPackages_Impl::accept (Visitor * v)
  {
    v->visit_ComponentPackages (this);
  }

  //
  // _create
  //
  ComponentPackages ComponentPackages_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentPackages> (parent, ComponentPackages_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ComponentPackages_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

