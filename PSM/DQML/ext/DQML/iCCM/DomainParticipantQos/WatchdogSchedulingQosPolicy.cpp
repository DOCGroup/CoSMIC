// $Id$

#include "StdAfx.h"
#include "WatchdogSchedulingQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "WatchdogSchedulingQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string WatchdogSchedulingQosPolicy_Impl::metaname ("WatchdogSchedulingQosPolicy");

  //
  // is_abstract
  //
  const bool WatchdogSchedulingQosPolicy_Impl::is_abstract = false;

  //
  // _create (const Participant_in)
  //
  WatchdogSchedulingQosPolicy WatchdogSchedulingQosPolicy_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create < WatchdogSchedulingQosPolicy > (parent, WatchdogSchedulingQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void WatchdogSchedulingQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WatchdogSchedulingQosPolicy (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Participant
  //
  Participant WatchdogSchedulingQosPolicy_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }
}

