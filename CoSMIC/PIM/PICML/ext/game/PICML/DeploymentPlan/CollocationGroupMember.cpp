// $Id$

#include "stdafx.h"
#include "CollocationGroupMember.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/DeploymentPlan/DeploymentPlan.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CollocationGroupMember_Impl::metaname = "CollocationGroupMember";

  //
  // CollocationGroupMember_Impl
  //
  CollocationGroupMember_Impl::CollocationGroupMember_Impl (void)
  {
  }

  //
  // CollocationGroupMember_Impl
  //
  CollocationGroupMember_Impl::CollocationGroupMember_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CollocationGroupMember_Impl
  //
  CollocationGroupMember_Impl::~CollocationGroupMember_Impl (void)
  {
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan CollocationGroupMember_Impl::parent_DeploymentPlan (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlan> (this->object_.p);
  }
}

