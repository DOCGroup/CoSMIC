// $Id$

#include "stdafx.h"
#include "DeploymentPlans.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DeploymentPlans_Impl::metaname = "DeploymentPlans";

  //
  // DeploymentPlans_Impl
  //
  DeploymentPlans_Impl::DeploymentPlans_Impl (void)
  {
  }

  //
  // DeploymentPlans_Impl
  //
  DeploymentPlans_Impl::DeploymentPlans_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DeploymentPlans_Impl
  //
  DeploymentPlans_Impl::~DeploymentPlans_Impl (void)
  {
  }

  //
  // accept
  //
  void DeploymentPlans_Impl::accept (Visitor * v)
  {
    v->visit_DeploymentPlans (this);
  }

  //
  // _create
  //
  DeploymentPlans DeploymentPlans_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <DeploymentPlans> (parent, DeploymentPlans_Impl::metaname);
  }

  ::GAME::Mga::RootFolder DeploymentPlans_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

