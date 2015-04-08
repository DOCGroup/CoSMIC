#include "StdAfx.h"
#include "CollocationGroup.h"

#if !defined (__GAME_INLINE__)
#include "CollocationGroup.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CollocationGroup_Impl::metaname ("CollocationGroup");

  //
  // is_abstract
  //
  const bool CollocationGroup_Impl::is_abstract = false;

  //
  // _create (const DeploymentPlan_in)
  //
  CollocationGroup CollocationGroup_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create < CollocationGroup > (parent, CollocationGroup_Impl::metaname);
  }

  //
  // accept
  //
  void CollocationGroup_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_CollocationGroup (this);
    else
      v->visit_Set (this);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan CollocationGroup_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // src_of_InstanceMapping
  //
  size_t CollocationGroup_Impl::src_of_InstanceMapping (std::vector <InstanceMapping> & items) const
  {
    return this->in_connections <InstanceMapping> (items);
  }

  //
  // has_src_of_InstanceMapping
  //
  bool CollocationGroup_Impl::has_src_of_InstanceMapping (void) const
  {
    return this->in_connections <InstanceMapping> ("src").count () == 1;
  }

  //
  // src_of_InstanceMapping
  //
  InstanceMapping CollocationGroup_Impl::src_of_InstanceMapping (void) const
  {
    return this->in_connections <InstanceMapping> ("src").first ();
  }

  //
  // dst_of_CollocationGroupProperty
  //
  size_t CollocationGroup_Impl::dst_of_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const
  {
    return this->in_connections <CollocationGroupProperty> (items);
  }

  //
  // dst_of_CollocationGroupProperty
  //
  GAME::Mga::Collection_T <CollocationGroupProperty> CollocationGroup_Impl::dst_of_CollocationGroupProperty (void) const
  {
    return this->in_connections <CollocationGroupProperty> ("dst");
  }

  //
  // members_CollocationGroupMember
  //
  ::GAME::Mga::Collection_T <CollocationGroupMember> CollocationGroup_Impl::members_CollocationGroupMember (void)
  {
    return this->members <CollocationGroupMember> ();
  }
}

