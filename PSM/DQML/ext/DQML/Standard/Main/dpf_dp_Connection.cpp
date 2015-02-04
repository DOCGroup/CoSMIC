// $Id$

#include "StdAfx.h"
#include "dpf_dp_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dpf_dp_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DDSEntities/DomainParticipantFactory.h"
#include "DQML/Standard/DDSEntities/DomainParticipant.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool dpf_dp_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, DomainParticipantFactory_in src, DomainParticipant_in dst)
  //
  dpf_dp_Connection dpf_dp_Connection_Impl::_create (const DDSQoS_in parent, DomainParticipantFactory_in src, DomainParticipant_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dpf_dp_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dpf_dp_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dpf_dp_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dpf_dp_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
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

