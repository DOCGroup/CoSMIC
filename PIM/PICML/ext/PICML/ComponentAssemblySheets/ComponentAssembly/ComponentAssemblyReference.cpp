// $Id$

#include "StdAfx.h"
#include "ComponentAssemblyReference.h"

#if !defined (__GAME_INLINE__)
#include "ComponentAssemblyReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentAssemblyReference_Impl::metaname ("ComponentAssemblyReference");

  //
  // is_abstract
  //
  const bool ComponentAssemblyReference_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  ComponentAssemblyReference ComponentAssemblyReference_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < ComponentAssemblyReference > (parent, ComponentAssemblyReference_Impl::metaname);
  }

  //
  // _create (const DeploymentPlan_in)
  //
  ComponentAssemblyReference ComponentAssemblyReference_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create < ComponentAssemblyReference > (parent, ComponentAssemblyReference_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentAssemblyReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentAssemblyReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ComponentAssemblyReference_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // ComponentAssembly_is_nil
  //
  bool ComponentAssemblyReference_Impl::ComponentAssembly_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_ComponentAssembly
  //
  void ComponentAssemblyReference_Impl::refers_to_ComponentAssembly (ComponentAssembly_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ComponentAssembly
  //
  ComponentAssembly ComponentAssemblyReference_Impl::refers_to_ComponentAssembly (void) const
  {
    return ComponentAssembly::_narrow (this->refers_to ());
  }
}

