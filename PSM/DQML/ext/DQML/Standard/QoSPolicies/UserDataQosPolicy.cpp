// $Id$

#include "StdAfx.h"
#include "UserDataQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "UserDataQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/UserDataQosPolicy/dp_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dr_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dw_userdata_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string UserDataQosPolicy_Impl::metaname ("UserDataQosPolicy");

  //
  // _create (const DataWriterQos_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const Participant_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create_object < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void UserDataQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_UserDataQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dp_userdata_Connection
  //
  size_t UserDataQosPolicy_Impl::dst_dp_userdata_Connection (std::vector <dp_userdata_Connection> & items) const
  {
    return this->in_connections <dp_userdata_Connection> (items);
  }

  //
  // dst_dr_userdata_Connection
  //
  size_t UserDataQosPolicy_Impl::dst_dr_userdata_Connection (std::vector <dr_userdata_Connection> & items) const
  {
    return this->in_connections <dr_userdata_Connection> (items);
  }

  //
  // dst_dw_userdata_Connection
  //
  size_t UserDataQosPolicy_Impl::dst_dw_userdata_Connection (std::vector <dw_userdata_Connection> & items) const
  {
    return this->in_connections <dw_userdata_Connection> (items);
  }
}
