// $Id$

#include "StdAfx.h"
#include "ComponentFactoryRef.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactoryRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
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
  // _create (const DeploymentPlan_in)
  //
  ComponentFactoryRef ComponentFactoryRef_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < ComponentFactoryRef > (parent, ComponentFactoryRef_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactoryRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentFactoryRef (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // src_Deploys
  //
  size_t ComponentFactoryRef_Impl::src_Deploys (std::vector <Deploys> & items) const
  {
    return this->in_connections <Deploys> (items);
  }

  //
  // ComponentFactoryInstance_is_nil
  //
  bool ComponentFactoryRef_Impl::ComponentFactoryInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ComponentFactoryInstance
  //
  ComponentFactoryInstance ComponentFactoryRef_Impl::get_ComponentFactoryInstance (void) const
  {
    return ComponentFactoryInstance::_narrow (this->refers_to ());
  }
}

