// $Id$

#include "StdAfx.h"
#include "SchedulingQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "SchedulingQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/SchedulingPriorityQosPolicy.h"
#include "DQML/Standard/QoSPolicies/SchedulingClassQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string SchedulingQosPolicy_Impl::metaname ("SchedulingQosPolicy");

  //
  // is_abstract
  //
  const bool SchedulingQosPolicy_Impl::is_abstract = false;

  //
  // accept
  //
  void SchedulingQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SchedulingQosPolicy (this);
    else
      v->visit_Model (this);
  }

  //
  // has_SchedulingPriorityQosPolicy
  //
  bool SchedulingQosPolicy_Impl::has_SchedulingPriorityQosPolicy (void) const
  {
    return this->children <SchedulingPriorityQosPolicy> ().count () == 1;
  }

  //
  // get_SchedulingPriorityQosPolicy
  //
  SchedulingPriorityQosPolicy SchedulingQosPolicy_Impl::get_SchedulingPriorityQosPolicy (void) const
  {
    return this->children <SchedulingPriorityQosPolicy> ().first ();
  }

  //
  // has_SchedulingClassQosPolicy
  //
  bool SchedulingQosPolicy_Impl::has_SchedulingClassQosPolicy (void) const
  {
    return this->children <SchedulingClassQosPolicy> ().count () == 1;
  }

  //
  // get_SchedulingClassQosPolicy
  //
  SchedulingClassQosPolicy SchedulingQosPolicy_Impl::get_SchedulingClassQosPolicy (void) const
  {
    return this->children <SchedulingClassQosPolicy> ().first ();
  }
}

