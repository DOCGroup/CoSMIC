// $Id$

#include "stdafx.h"
#include "Deploys.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Deploys_Impl::metaname = "Deploys";

  //
  // Deploys_Impl
  //
  Deploys_Impl::Deploys_Impl (void)
  {
  }

  //
  // Deploys_Impl
  //
  Deploys_Impl::Deploys_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Deploys_Impl
  //
  Deploys_Impl::~Deploys_Impl (void)
  {
  }

  //
  // accept
  //
  void Deploys_Impl::accept (Visitor * v)
  {
    v->visit_Deploys (this);
  }

  //
  // _create
  //
  Deploys Deploys_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object <Deploys> (parent, Deploys_Impl::metaname);
  }

  //
  // src_ComponentFactoryRef
  //
  ComponentFactoryRef Deploys_Impl::src_ComponentFactoryRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentFactoryRef::_narrow (target);
  }

  //
  // dst_ComponentInstanceRef
  //
  ComponentInstanceRef Deploys_Impl::dst_ComponentInstanceRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentInstanceRef::_narrow (target);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan Deploys_Impl::parent_DeploymentPlan (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlan> (this->object_.p);
  }
}

