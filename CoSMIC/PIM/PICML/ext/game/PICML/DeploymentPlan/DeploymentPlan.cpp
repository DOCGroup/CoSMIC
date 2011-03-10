// $Id$

#include "stdafx.h"
#include "DeploymentPlan.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/Common/Property.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "PICML/DeploymentPlan/DeploymentPlans.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DeploymentPlan_Impl::metaname = "DeploymentPlan";

  //
  // DeploymentPlan_Impl
  //
  DeploymentPlan_Impl::DeploymentPlan_Impl (void)
  {
  }

  //
  // DeploymentPlan_Impl
  //
  DeploymentPlan_Impl::DeploymentPlan_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DeploymentPlan_Impl
  //
  DeploymentPlan_Impl::~DeploymentPlan_Impl (void)
  {
  }

  //
  // accept
  //
  void DeploymentPlan_Impl::accept (Visitor * v)
  {
    v->visit_DeploymentPlan (this);
  }

  //
  // _create
  //
  DeploymentPlan DeploymentPlan_Impl::_create (const DeploymentPlans_in parent)
  {
    return ::GAME::Mga::create_root_object <DeploymentPlan> (parent, DeploymentPlan_Impl::metaname);
  }

  //
  // get_CollocationGroups
  //
  size_t DeploymentPlan_Impl::get_CollocationGroups (std::vector <CollocationGroup> & items) const
  {
    return this->children (items);
  }

  //
  // get_InstanceMappings
  //
  size_t DeploymentPlan_Impl::get_InstanceMappings (std::vector <InstanceMapping> & items) const
  {
    return this->children (items);
  }

  //
  // get_Deployss
  //
  size_t DeploymentPlan_Impl::get_Deployss (std::vector <Deploys> & items) const
  {
    return this->children (items);
  }

  //
  // get_NodeReferences
  //
  size_t DeploymentPlan_Impl::get_NodeReferences (std::vector <NodeReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t DeploymentPlan_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_PropertyMappings
  //
  size_t DeploymentPlan_Impl::get_PropertyMappings (std::vector <PropertyMapping> & items) const
  {
    return this->children (items);
  }

  //
  // get_CollocationGroupPropertys
  //
  size_t DeploymentPlan_Impl::get_CollocationGroupPropertys (std::vector <CollocationGroupProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_CollocationGroupMembers
  //
  size_t DeploymentPlan_Impl::get_CollocationGroupMembers (std::vector <CollocationGroupMember> & items) const
  {
    return this->children (items);
  }

  //
  // parent_DeploymentPlans
  //
  DeploymentPlans DeploymentPlan_Impl::parent_DeploymentPlans (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlans> (this->object_.p);
  }
}

