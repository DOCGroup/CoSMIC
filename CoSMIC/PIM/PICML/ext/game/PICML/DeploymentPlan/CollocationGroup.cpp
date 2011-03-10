// $Id$

#include "stdafx.h"
#include "CollocationGroup.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "PICML/DeploymentPlan/CollocationGroupProperty.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CollocationGroup_Impl::metaname = "CollocationGroup";

  //
  // CollocationGroup_Impl
  //
  CollocationGroup_Impl::CollocationGroup_Impl (void)
  {
  }

  //
  // CollocationGroup_Impl
  //
  CollocationGroup_Impl::CollocationGroup_Impl (IMgaSet * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CollocationGroup_Impl
  //
  CollocationGroup_Impl::~CollocationGroup_Impl (void)
  {
  }

  //
  // accept
  //
  void CollocationGroup_Impl::accept (Visitor * v)
  {
    v->visit_CollocationGroup (this);
  }

  //
  // _create
  //
  CollocationGroup CollocationGroup_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object <CollocationGroup> (parent, CollocationGroup_Impl::metaname);
  }

  //
  // in_InstanceMapping_connections
  //
  size_t CollocationGroup_Impl::in_InstanceMapping_connections (std::vector <InstanceMapping> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_CollocationGroupProperty_connections
  //
  size_t CollocationGroup_Impl::in_CollocationGroupProperty_connections (std::vector <CollocationGroupProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan CollocationGroup_Impl::parent_DeploymentPlan (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlan> (this->object_.p);
  }
}

