// $Id$

#include "StdAfx.h"
#include "CollocationGroup.h"

#if !defined (__GAME_INLINE__)
#include "CollocationGroup.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssemblyReference.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
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
  // _create (const DeploymentPlan_in)
  //
  CollocationGroup CollocationGroup_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < CollocationGroup > (parent, CollocationGroup_Impl::metaname);
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
  // src_InstanceMapping
  //
  size_t CollocationGroup_Impl::src_InstanceMapping (std::vector <InstanceMapping> & items) const
  {
    return this->in_connections <InstanceMapping> (items);
  }

  //
  // dst_CollocationGroupProperty
  //
  size_t CollocationGroup_Impl::dst_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const
  {
    return this->in_connections <CollocationGroupProperty> (items);
  }
}

