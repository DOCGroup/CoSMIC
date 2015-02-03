// $Id$

#include "StdAfx.h"
#include "Deploys.h"

#if !defined (__GAME_INLINE__)
#include "Deploys.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/DeploymentPlan/ComponentInstanceRef.h"
#include "PICML/DeploymentPlan/ComponentFactoryRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Deploys_Impl::metaname ("Deploys");

  //
  // is_abstract
  //
  const bool Deploys_Impl::is_abstract (0);

  //
  // _create (const DeploymentPlan_in, ComponentFactoryRef_in src, ComponentInstanceRef_in dst)
  //
  Deploys Deploys_Impl::_create (const DeploymentPlan_in parent, ComponentFactoryRef_in src, ComponentInstanceRef_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Deploys_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Deploys_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Deploys (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan Deploys_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // ComponentFactoryRef
  //
  ComponentFactoryRef Deploys_Impl::src_ComponentFactoryRef (void) const
  {
    return ComponentFactoryRef::_narrow (this->src ());
  }

  //
  // ComponentInstanceRef
  //
  ComponentInstanceRef Deploys_Impl::dst_ComponentInstanceRef (void) const
  {
    return ComponentInstanceRef::_narrow (this->dst ());
  }
}

