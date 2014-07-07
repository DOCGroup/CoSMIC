// $Id$

#include "StdAfx.h"
#include "SchedulingClassQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "SchedulingClassQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/SchedulingQosPolicy/SchedulingQosPolicy.h"
#include "DQML/iCCM/DomainParticipantQos/WatchdogSchedulingQosPolicy.h"
#include "DQML/iCCM/DomainParticipantQos/ListenerSchedulingQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string SchedulingClassQosPolicy_Impl::metaname ("SchedulingClassQosPolicy");

  //
  // _create (const SchedulingQosPolicy_in)
  //
  SchedulingClassQosPolicy SchedulingClassQosPolicy_Impl::_create (const SchedulingQosPolicy_in parent)
  {
    return ::GAME::Mga::create_object < SchedulingClassQosPolicy > (parent, SchedulingClassQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  SchedulingClassQosPolicy SchedulingClassQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < SchedulingClassQosPolicy > (parent, SchedulingClassQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void SchedulingClassQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SchedulingClassQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_SchedulingQosPolicy
  //
  SchedulingQosPolicy SchedulingClassQosPolicy_Impl::parent_SchedulingQosPolicy (void)
  {
    return SchedulingQosPolicy::_narrow (this->parent ());
  }
}

