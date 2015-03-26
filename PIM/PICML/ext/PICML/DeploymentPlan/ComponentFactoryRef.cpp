// $Id$

#include "StdAfx.h"
#include "ComponentFactoryRef.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactoryRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryRef_Impl::metaname ("ComponentFactoryRef");

  //
  // is_abstract
  //
  const bool ComponentFactoryRef_Impl::is_abstract = false;

  //
  // _create (const DeploymentPlan_in)
  //
  ComponentFactoryRef ComponentFactoryRef_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create < ComponentFactoryRef > (parent, ComponentFactoryRef_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactoryRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentFactoryRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // src_of_Deploys
  //
  size_t ComponentFactoryRef_Impl::src_of_Deploys (std::vector <Deploys> & items) const
  {
    return this->in_connections <Deploys> (items);
  }

  //
  // src_of_Deploys
  //
  GAME::Mga::Collection_T <Deploys> ComponentFactoryRef_Impl::src_of_Deploys (void) const
  {
    return this->in_connections <Deploys> ("src");
  }

  //
  // ComponentFactoryInstance_is_nil
  //
  bool ComponentFactoryRef_Impl::ComponentFactoryInstance_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_ComponentFactoryInstance
  //
  void ComponentFactoryRef_Impl::refers_to_ComponentFactoryInstance (ComponentFactoryInstance_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ComponentFactoryInstance
  //
  ComponentFactoryInstance ComponentFactoryRef_Impl::refers_to_ComponentFactoryInstance (void) const
  {
    return ComponentFactoryInstance::_narrow (this->refers_to ());
  }
}

