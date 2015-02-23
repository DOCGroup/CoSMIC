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
  // is_abstract
  //
  const bool ComponentInstanceRef_Impl::is_abstract = false;

  //
  // _create (const DeploymentPlan_in)
  //
  ComponentInstanceRef ComponentInstanceRef_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create < ComponentInstanceRef > (parent, ComponentInstanceRef_Impl::metaname);
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
  // dst_of_Deploys
  //
  size_t ComponentInstanceRef_Impl::dst_of_Deploys (std::vector <Deploys> & items) const
  {
    return this->in_connections <Deploys> (items);
  }

  //
  // has_dst_of_Deploys
  //
  bool ComponentInstanceRef_Impl::has_dst_of_Deploys (void) const
  {
    return this->in_connections <Deploys> ("dst").count () == 1;
  }

  //
  // dst_of_Deploys
  //
  Deploys ComponentInstanceRef_Impl::dst_of_Deploys (void) const
  {
    return this->in_connections <Deploys> ("dst").first ();
  }

  //
  // ComponentInstance_is_nil
  //
  bool ComponentInstanceRef_Impl::ComponentInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ComponentInstance
  //
  void ComponentInstanceRef_Impl::refers_to_ComponentInstance (ComponentInstance_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ComponentInstance
  //
  ComponentInstance ComponentInstanceRef_Impl::refers_to_ComponentInstance (void) const
  {
    return ComponentInstance::_narrow (this->refers_to ());
  }
}

