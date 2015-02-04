// $Id$

#include "StdAfx.h"
#include "UserDataQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "UserDataQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/Standard/UserDataQosPolicy/dw_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dp_userdata_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dr_userdata_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool UserDataQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataReaderQos_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const Participant_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const Participant_in parent)
  {
    return ::GAME::Mga::create < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  UserDataQosPolicy UserDataQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < UserDataQosPolicy > (parent, UserDataQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void UserDataQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_UserDataQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos UserDataQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos UserDataQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_Participant
  //
  Participant UserDataQosPolicy_Impl::parent_Participant (void)
  {
    return Participant::_narrow (this->parent ());
  }

  //
  // dst_of_dw_userdata_Connection
  //
  size_t UserDataQosPolicy_Impl::dst_of_dw_userdata_Connection (std::vector <dw_userdata_Connection> & items) const
  {
    return this->in_connections <dw_userdata_Connection> (items);
  }

  //
  // dst_of_dw_userdata_Connection
  //
  GAME::Mga::Collection_T <dw_userdata_Connection> UserDataQosPolicy_Impl::dst_of_dw_userdata_Connection (void) const
  {
    return this->in_connections <dw_userdata_Connection> ("dst");
  }

  //
  // dst_of_dp_userdata_Connection
  //
  size_t UserDataQosPolicy_Impl::dst_of_dp_userdata_Connection (std::vector <dp_userdata_Connection> & items) const
  {
    return this->in_connections <dp_userdata_Connection> (items);
  }

  //
  // dst_of_dp_userdata_Connection
  //
  GAME::Mga::Collection_T <dp_userdata_Connection> UserDataQosPolicy_Impl::dst_of_dp_userdata_Connection (void) const
  {
    return this->in_connections <dp_userdata_Connection> ("dst");
  }

  //
  // dst_of_dr_userdata_Connection
  //
  size_t UserDataQosPolicy_Impl::dst_of_dr_userdata_Connection (std::vector <dr_userdata_Connection> & items) const
  {
    return this->in_connections <dr_userdata_Connection> (items);
  }

  //
  // dst_of_dr_userdata_Connection
  //
  GAME::Mga::Collection_T <dr_userdata_Connection> UserDataQosPolicy_Impl::dst_of_dr_userdata_Connection (void) const
  {
    return this->in_connections <dr_userdata_Connection> ("dst");
  }
}

