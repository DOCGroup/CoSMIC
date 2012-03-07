// $Id$

#include "StdAfx.h"
#include "DeploymentPlan.h"

#if !defined (__GAME_INLINE__)
#include "DeploymentPlan.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/DeploymentPlan/DeploymentPlans.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/TargetElements/NodeReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DeploymentPlan_Impl::metaname ("DeploymentPlan");

  //
  // _create (const DeploymentPlans_in)
  //
  DeploymentPlan DeploymentPlan_Impl::_create (const DeploymentPlans_in parent)
  {
    return ::GAME::Mga::create_root_object < DeploymentPlan > (parent, DeploymentPlan_Impl::metaname);
  }

  //
  // accept
  //
  void DeploymentPlan_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DeploymentPlan (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_Propertys
  //
  size_t DeploymentPlan_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> DeploymentPlan_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }

  //
  // get_InstanceMappings
  //
  size_t DeploymentPlan_Impl::get_InstanceMappings (std::vector <InstanceMapping> & items) const
  {
    return this->children (items);
  }

  //
  // get_InstanceMappings
  //
  ::GAME::Mga::Iterator <InstanceMapping> DeploymentPlan_Impl::get_InstanceMappings (void) const
  {
    return this->children <InstanceMapping> ();
  }

  //
  // get_CollocationGroups
  //
  size_t DeploymentPlan_Impl::get_CollocationGroups (std::vector <CollocationGroup> & items) const
  {
    return this->children (items);
  }

  //
  // get_CollocationGroups
  //
  ::GAME::Mga::Iterator <CollocationGroup> DeploymentPlan_Impl::get_CollocationGroups (void) const
  {
    return this->children <CollocationGroup> ();
  }

  //
  // get_Deployss
  //
  size_t DeploymentPlan_Impl::get_Deployss (std::vector <Deploys> & items) const
  {
    return this->children (items);
  }

  //
  // get_Deployss
  //
  ::GAME::Mga::Iterator <Deploys> DeploymentPlan_Impl::get_Deployss (void) const
  {
    return this->children <Deploys> ();
  }

  //
  // get_CollocationGroupMembers
  //
  size_t DeploymentPlan_Impl::get_CollocationGroupMembers (std::vector <CollocationGroupMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_CollocationGroupMembers
  //
  ::GAME::Mga::Iterator <CollocationGroupMember> DeploymentPlan_Impl::get_CollocationGroupMembers (void) const
  {
    return this->children <CollocationGroupMember> ();
  }

  //
  // get_PropertyMappings
  //
  size_t DeploymentPlan_Impl::get_PropertyMappings (std::vector <PropertyMapping> & items) const
  {
    return this->children (items);
  }

  //
  // get_PropertyMappings
  //
  ::GAME::Mga::Iterator <PropertyMapping> DeploymentPlan_Impl::get_PropertyMappings (void) const
  {
    return this->children <PropertyMapping> ();
  }

  //
  // get_CollocationGroupPropertys
  //
  size_t DeploymentPlan_Impl::get_CollocationGroupPropertys (std::vector <CollocationGroupProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_CollocationGroupPropertys
  //
  ::GAME::Mga::Iterator <CollocationGroupProperty> DeploymentPlan_Impl::get_CollocationGroupPropertys (void) const
  {
    return this->children <CollocationGroupProperty> ();
  }

  //
  // get_NodeReferences
  //
  size_t DeploymentPlan_Impl::get_NodeReferences (std::vector <NodeReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_NodeReferences
  //
  ::GAME::Mga::Iterator <NodeReference> DeploymentPlan_Impl::get_NodeReferences (void) const
  {
    return this->children <NodeReference> ();
  }
}

