#include "StdAfx.h"
#include "CollocationGroupMember.h"

#if !defined (__GAME_INLINE__)
#include "CollocationGroupMember.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CollocationGroupMember_Impl::metaname ("CollocationGroupMember");

  //
  // is_abstract
  //
  const bool CollocationGroupMember_Impl::is_abstract = true;

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan CollocationGroupMember_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }
}

