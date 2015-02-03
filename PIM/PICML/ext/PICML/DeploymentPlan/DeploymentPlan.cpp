// $Id$

#include "StdAfx.h"
#include "DeploymentPlan.h"

#if !defined (__GAME_INLINE__)
#include "DeploymentPlan.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"
#include "PICML/DeploymentPlan/DeploymentPlans.h"
#include "PICML/DeploymentPlan/Deploys.h"
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
  // is_abstract
  //
  const bool DeploymentPlan_Impl::is_abstract (0);

  //
  // _create (const DeploymentPlans_in)
  //
  DeploymentPlan DeploymentPlan_Impl::_create (const DeploymentPlans_in parent)
  {
    return ::GAME::Mga::create < DeploymentPlan > (parent, DeploymentPlan_Impl::metaname);
  }

  //
  // accept
  //
  void DeploymentPlan_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DeploymentPlan (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_DeploymentPlans
  //
  DeploymentPlans DeploymentPlan_Impl::parent_DeploymentPlans (void)
  {
    return DeploymentPlans::_narrow (this->parent ());
  }

  //
  // get_ComponentAssemblyReferences
  //
  size_t DeploymentPlan_Impl::get_ComponentAssemblyReferences (std::vector <ComponentAssemblyReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentAssemblyReferences
  //
  ::GAME::Mga::Collection_T <ComponentAssemblyReference> DeploymentPlan_Impl::get_ComponentAssemblyReferences (void) const
  {
    return this->children <ComponentAssemblyReference> ();
  }

  //
  // get_ComponentInstanceRefs
  //
  size_t DeploymentPlan_Impl::get_ComponentInstanceRefs (std::vector <ComponentInstanceRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentInstanceRefs
  //
  ::GAME::Mga::Collection_T <ComponentInstanceRef> DeploymentPlan_Impl::get_ComponentInstanceRefs (void) const
  {
    return this->children <ComponentInstanceRef> ();
  }

  //
  // get_ComponentFactoryRefs
  //
  size_t DeploymentPlan_Impl::get_ComponentFactoryRefs (std::vector <ComponentFactoryRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentFactoryRefs
  //
  ::GAME::Mga::Collection_T <ComponentFactoryRef> DeploymentPlan_Impl::get_ComponentFactoryRefs (void) const
  {
    return this->children <ComponentFactoryRef> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t DeploymentPlan_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> DeploymentPlan_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t DeploymentPlan_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> DeploymentPlan_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
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
  ::GAME::Mga::Collection_T <CollocationGroupProperty> DeploymentPlan_Impl::get_CollocationGroupPropertys (void) const
  {
    return this->children <CollocationGroupProperty> ();
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
  ::GAME::Mga::Collection_T <CollocationGroup> DeploymentPlan_Impl::get_CollocationGroups (void) const
  {
    return this->children <CollocationGroup> ();
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
  ::GAME::Mga::Collection_T <InstanceMapping> DeploymentPlan_Impl::get_InstanceMappings (void) const
  {
    return this->children <InstanceMapping> ();
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
  ::GAME::Mga::Collection_T <NodeReference> DeploymentPlan_Impl::get_NodeReferences (void) const
  {
    return this->children <NodeReference> ();
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
  ::GAME::Mga::Collection_T <PropertyMapping> DeploymentPlan_Impl::get_PropertyMappings (void) const
  {
    return this->children <PropertyMapping> ();
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
  ::GAME::Mga::Collection_T <Deploys> DeploymentPlan_Impl::get_Deployss (void) const
  {
    return this->children <Deploys> ();
  }
}

