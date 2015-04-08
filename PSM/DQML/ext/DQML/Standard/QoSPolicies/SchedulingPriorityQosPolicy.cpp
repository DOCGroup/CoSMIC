#include "StdAfx.h"
#include "SchedulingPriorityQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "SchedulingPriorityQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/SchedulingQosPolicy/SchedulingQosPolicy.h"
#include "DQML/iCCM/DomainParticipantQos/ListenerSchedulingQosPolicy.h"
#include "DQML/iCCM/DomainParticipantQos/WatchdogSchedulingQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string SchedulingPriorityQosPolicy_Impl::metaname ("SchedulingPriorityQosPolicy");

  //
  // is_abstract
  //
  const bool SchedulingPriorityQosPolicy_Impl::is_abstract = false;

  //
  // _create (const SchedulingQosPolicy_in)
  //
  SchedulingPriorityQosPolicy SchedulingPriorityQosPolicy_Impl::_create (const SchedulingQosPolicy_in parent)
  {
    return ::GAME::Mga::create < SchedulingPriorityQosPolicy > (parent, SchedulingPriorityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  SchedulingPriorityQosPolicy SchedulingPriorityQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < SchedulingPriorityQosPolicy > (parent, SchedulingPriorityQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void SchedulingPriorityQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SchedulingPriorityQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_SchedulingQosPolicy
  //
  SchedulingQosPolicy SchedulingPriorityQosPolicy_Impl::parent_SchedulingQosPolicy (void)
  {
    return SchedulingQosPolicy::_narrow (this->parent ());
  }
}

