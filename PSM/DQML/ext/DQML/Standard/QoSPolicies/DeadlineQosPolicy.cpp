// $Id$

#include "StdAfx.h"
#include "DeadlineQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DeadlineQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/Standard/DeadlineQosPolicy/dr_deadline_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/dw_deadline_Connection.h"
#include "DQML/Standard/DeadlineQosPolicy/top_deadline_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DeadlineQosPolicy_Impl::metaname ("DeadlineQosPolicy");

  //
  // is_abstract
  //
  const bool DeadlineQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataReaderQos_in)
  //
  DeadlineQosPolicy DeadlineQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < DeadlineQosPolicy > (parent, DeadlineQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  DeadlineQosPolicy DeadlineQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < DeadlineQosPolicy > (parent, DeadlineQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  DeadlineQosPolicy DeadlineQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < DeadlineQosPolicy > (parent, DeadlineQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DeadlineQosPolicy DeadlineQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DeadlineQosPolicy > (parent, DeadlineQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DeadlineQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DeadlineQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos DeadlineQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos DeadlineQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos DeadlineQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_of_dr_deadline_Connection
  //
  size_t DeadlineQosPolicy_Impl::dst_of_dr_deadline_Connection (std::vector <dr_deadline_Connection> & items) const
  {
    return this->in_connections <dr_deadline_Connection> (items);
  }

  //
  // dst_of_dr_deadline_Connection
  //
  GAME::Mga::Collection_T <dr_deadline_Connection> DeadlineQosPolicy_Impl::dst_of_dr_deadline_Connection (void) const
  {
    return this->in_connections <dr_deadline_Connection> ("dst");
  }

  //
  // dst_of_dw_deadline_Connection
  //
  size_t DeadlineQosPolicy_Impl::dst_of_dw_deadline_Connection (std::vector <dw_deadline_Connection> & items) const
  {
    return this->in_connections <dw_deadline_Connection> (items);
  }

  //
  // dst_of_dw_deadline_Connection
  //
  GAME::Mga::Collection_T <dw_deadline_Connection> DeadlineQosPolicy_Impl::dst_of_dw_deadline_Connection (void) const
  {
    return this->in_connections <dw_deadline_Connection> ("dst");
  }

  //
  // dst_of_top_deadline_Connection
  //
  size_t DeadlineQosPolicy_Impl::dst_of_top_deadline_Connection (std::vector <top_deadline_Connection> & items) const
  {
    return this->in_connections <top_deadline_Connection> (items);
  }

  //
  // dst_of_top_deadline_Connection
  //
  GAME::Mga::Collection_T <top_deadline_Connection> DeadlineQosPolicy_Impl::dst_of_top_deadline_Connection (void) const
  {
    return this->in_connections <top_deadline_Connection> ("dst");
  }
}

