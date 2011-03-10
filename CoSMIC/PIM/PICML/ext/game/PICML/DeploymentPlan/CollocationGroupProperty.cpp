// $Id$

#include "stdafx.h"
#include "CollocationGroupProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/Common/Property.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CollocationGroupProperty_Impl::metaname = "CollocationGroupProperty";

  //
  // CollocationGroupProperty_Impl
  //
  CollocationGroupProperty_Impl::CollocationGroupProperty_Impl (void)
  {
  }

  //
  // CollocationGroupProperty_Impl
  //
  CollocationGroupProperty_Impl::CollocationGroupProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CollocationGroupProperty_Impl
  //
  CollocationGroupProperty_Impl::~CollocationGroupProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void CollocationGroupProperty_Impl::accept (Visitor * v)
  {
    v->visit_CollocationGroupProperty (this);
  }

  //
  // _create
  //
  CollocationGroupProperty CollocationGroupProperty_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object <CollocationGroupProperty> (parent, CollocationGroupProperty_Impl::metaname);
  }

  //
  // src_Property
  //
  Property CollocationGroupProperty_Impl::src_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Property::_narrow (target);
  }

  //
  // dst_CollocationGroup
  //
  CollocationGroup CollocationGroupProperty_Impl::dst_CollocationGroup (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return CollocationGroup::_narrow (target);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan CollocationGroupProperty_Impl::parent_DeploymentPlan (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlan> (this->object_.p);
  }
}

