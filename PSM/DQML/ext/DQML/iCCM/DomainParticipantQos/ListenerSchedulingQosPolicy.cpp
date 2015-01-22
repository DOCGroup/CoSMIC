// $Id$

#include "StdAfx.h"
#include "ListenerSchedulingQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ListenerSchedulingQosPolicy.inl"
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
  const std::string ListenerSchedulingQosPolicy_Impl::metaname ("ListenerSchedulingQosPolicy");

  //
  // _create (const Participant_in)
  //
  ListenerSchedulingQosPolicy ListenerSchedulingQosPolicy_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create < ListenerSchedulingQosPolicy > (parent, ListenerSchedulingQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void ListenerSchedulingQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ListenerSchedulingQosPolicy (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Participant
  //
  Participant ListenerSchedulingQosPolicy_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }
}

