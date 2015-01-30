// $Id$

#include "StdAfx.h"
#include "CollocationGroupProperty.h"

#if !defined (__GAME_INLINE__)
#include "CollocationGroupProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CollocationGroupProperty_Impl::metaname ("CollocationGroupProperty");

  //
  // _create (const DeploymentPlan_in, Property_in src, CollocationGroup_in dst)
  //
  CollocationGroupProperty CollocationGroupProperty_Impl::_create (const DeploymentPlan_in parent, Property_in src, CollocationGroup_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, CollocationGroupProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void CollocationGroupProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_CollocationGroupProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan CollocationGroupProperty_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // Property
  //
  Property CollocationGroupProperty_Impl::src_Property (void) const
  {
    return Property::_narrow (this->src ());
  }

  //
  // CollocationGroup
  //
  CollocationGroup CollocationGroupProperty_Impl::dst_CollocationGroup (void) const
  {
    return CollocationGroup::_narrow (this->dst ());
  }
}

