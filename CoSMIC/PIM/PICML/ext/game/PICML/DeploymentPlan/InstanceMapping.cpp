// $Id$

#include "stdafx.h"
#include "InstanceMapping.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/TargetElements/NodeReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InstanceMapping_Impl::metaname = "InstanceMapping";

  //
  // InstanceMapping_Impl
  //
  InstanceMapping_Impl::InstanceMapping_Impl (void)
  {
  }

  //
  // InstanceMapping_Impl
  //
  InstanceMapping_Impl::InstanceMapping_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InstanceMapping_Impl
  //
  InstanceMapping_Impl::~InstanceMapping_Impl (void)
  {
  }

  //
  // accept
  //
  void InstanceMapping_Impl::accept (Visitor * v)
  {
    v->visit_InstanceMapping (this);
  }

  //
  // _create
  //
  InstanceMapping InstanceMapping_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object <InstanceMapping> (parent, InstanceMapping_Impl::metaname);
  }

  //
  // src_CollocationGroup
  //
  CollocationGroup InstanceMapping_Impl::src_CollocationGroup (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return CollocationGroup::_narrow (target);
  }

  //
  // dst_NodeReference
  //
  NodeReference InstanceMapping_Impl::dst_NodeReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return NodeReference::_narrow (target);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan InstanceMapping_Impl::parent_DeploymentPlan (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlan> (this->object_.p);
  }
}

