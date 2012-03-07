// $Id$

#include "StdAfx.h"
#include "DeploymentPlans.h"

#if !defined (__GAME_INLINE__)
#include "DeploymentPlans.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DeploymentPlans_Impl::metaname ("DeploymentPlans");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  DeploymentPlans DeploymentPlans_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <DeploymentPlans> (parent, DeploymentPlans_Impl::metaname);
  }

  //
  // accept
  //
  void DeploymentPlans_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DeploymentPlans (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_DeploymentPlans
  //
  size_t DeploymentPlans_Impl::get_DeploymentPlans (std::vector <DeploymentPlan> & items) const
  {
    return this->children (items);
  }
}

