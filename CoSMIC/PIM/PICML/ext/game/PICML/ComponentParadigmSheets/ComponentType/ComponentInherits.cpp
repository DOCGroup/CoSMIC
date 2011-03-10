// $Id$

#include "stdafx.h"
#include "ComponentInherits.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInherits_Impl::metaname = "ComponentInherits";

  //
  // ComponentInherits_Impl
  //
  ComponentInherits_Impl::ComponentInherits_Impl (void)
  {
  }

  //
  // ComponentInherits_Impl
  //
  ComponentInherits_Impl::ComponentInherits_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInherits_Impl
  //
  ComponentInherits_Impl::~ComponentInherits_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentInherits_Impl::accept (Visitor * v)
  {
    v->visit_ComponentInherits (this);
  }

  //
  // _create
  //
  ComponentInherits ComponentInherits_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object <ComponentInherits> (parent, ComponentInherits_Impl::metaname);
  }

  //
  // parent_Component
  //
  Component ComponentInherits_Impl::parent_Component (void) const
  {
    return ::GAME::Mga::get_parent <Component> (this->object_.p);
  }

  //
  // refers_to_Component
  //
  Component ComponentInherits_Impl::refers_to_Component (void) const
  {
    return ::GAME::Mga::get_refers_to <Component> (this);
  }
}

