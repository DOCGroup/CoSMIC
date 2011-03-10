// $Id$

#include "stdafx.h"
#include "ComponentAssemblyReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentAssemblyReference_Impl::metaname = "ComponentAssemblyReference";

  //
  // ComponentAssemblyReference_Impl
  //
  ComponentAssemblyReference_Impl::ComponentAssemblyReference_Impl (void)
  {
  }

  //
  // ComponentAssemblyReference_Impl
  //
  ComponentAssemblyReference_Impl::ComponentAssemblyReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentAssemblyReference_Impl
  //
  ComponentAssemblyReference_Impl::~ComponentAssemblyReference_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentAssemblyReference_Impl::accept (Visitor * v)
  {
    v->visit_ComponentAssemblyReference (this);
  }

  //
  // _create
  //
  ComponentAssemblyReference ComponentAssemblyReference_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object <ComponentAssemblyReference> (parent, ComponentAssemblyReference_Impl::metaname);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ComponentAssemblyReference_Impl::parent_ComponentAssembly (void) const
  {
    return ::GAME::Mga::get_parent <ComponentAssembly> (this->object_.p);
  }

  //
  // refers_to_ComponentAssembly
  //
  ComponentAssembly ComponentAssemblyReference_Impl::refers_to_ComponentAssembly (void) const
  {
    return ::GAME::Mga::get_refers_to <ComponentAssembly> (this);
  }
}

