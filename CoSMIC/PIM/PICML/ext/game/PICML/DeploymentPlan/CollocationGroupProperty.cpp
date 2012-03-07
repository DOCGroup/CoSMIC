// $Id$

#include "StdAfx.h"
#include "CollocationGroupProperty.h"

#if !defined (__GAME_INLINE__)
#include "CollocationGroupProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/DeploymentPlan/CollocationGroup.h"
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
  // _create (const DeploymentPlan_in)
  //
  CollocationGroupProperty CollocationGroupProperty_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < CollocationGroupProperty > (parent, CollocationGroupProperty_Impl::metaname);
  }

  //
  // accept
  //
  void CollocationGroupProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_CollocationGroupProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

