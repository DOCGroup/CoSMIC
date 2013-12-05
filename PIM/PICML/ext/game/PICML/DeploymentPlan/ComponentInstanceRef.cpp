// $Id$

#include "StdAfx.h"
#include "ComponentInstanceRef.h"

#if !defined (__GAME_INLINE__)
#include "ComponentInstanceRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstanceRef_Impl::metaname ("ComponentInstanceRef");

  //
  // _create (const DeploymentPlan_in)
  //
  ComponentInstanceRef ComponentInstanceRef_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < ComponentInstanceRef > (parent, ComponentInstanceRef_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInstanceRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentInstanceRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // dst_Deploys
  //
  size_t ComponentInstanceRef_Impl::dst_Deploys (std::vector <Deploys> & items) const
  {
    return this->in_connections <Deploys> (items);
  }

  //
  // ComponentInstance_is_nil
  //
  bool ComponentInstanceRef_Impl::ComponentInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ComponentInstance
  //
  void ComponentInstanceRef_Impl::set_ComponentInstance (ComponentInstance_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ComponentInstance
  //
  ComponentInstance ComponentInstanceRef_Impl::get_ComponentInstance (void) const
  {
    return ComponentInstance::_narrow (this->refers_to ());
  }
}

