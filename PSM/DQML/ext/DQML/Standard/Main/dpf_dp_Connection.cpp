// $Id$

#include "StdAfx.h"
#include "dpf_dp_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dpf_dp_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DomainParticipant.h"
#include "DQML/Standard/DDSEntities/DomainParticipantFactory.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dpf_dp_Connection_Impl::metaname ("dpf_dp_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dpf_dp_Connection dpf_dp_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dpf_dp_Connection > (parent, dpf_dp_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dpf_dp_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dpf_dp_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // DomainParticipantFactory
  //
  DomainParticipantFactory dpf_dp_Connection_Impl::src_DomainParticipantFactory (void) const
  {
    return DomainParticipantFactory::_narrow (this->src ());
  }

  //
  // DomainParticipant
  //
  DomainParticipant dpf_dp_Connection_Impl::dst_DomainParticipant (void) const
  {
    return DomainParticipant::_narrow (this->dst ());
  }
}

