// $Id$

#include "StdAfx.h"
#include "HistoryQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "HistoryQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/Standard/HistoryQosPolicy/dr_history_Connection.h"
#include "DQML/Standard/HistoryQosPolicy/dw_history_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/Standard/HistoryQosPolicy/topic_history_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string HistoryQosPolicy_Impl::metaname ("HistoryQosPolicy");

  //
  // is_abstract
  //
  const bool HistoryQosPolicy_Impl::is_abstract = false;

  //
  // _create (const TopicQos_in)
  //
  HistoryQosPolicy HistoryQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < HistoryQosPolicy > (parent, HistoryQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  HistoryQosPolicy HistoryQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < HistoryQosPolicy > (parent, HistoryQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  HistoryQosPolicy HistoryQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < HistoryQosPolicy > (parent, HistoryQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  HistoryQosPolicy HistoryQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < HistoryQosPolicy > (parent, HistoryQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void HistoryQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_HistoryQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_TopicQos
  //
  TopicQos HistoryQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos HistoryQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos HistoryQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // dst_of_dr_history_Connection
  //
  size_t HistoryQosPolicy_Impl::dst_of_dr_history_Connection (std::vector <dr_history_Connection> & items) const
  {
    return this->in_connections <dr_history_Connection> (items);
  }

  //
  // has_dst_of_dr_history_Connection
  //
  bool HistoryQosPolicy_Impl::has_dst_of_dr_history_Connection (void) const
  {
    return this->in_connections <dr_history_Connection> ("dst").count () == 1;
  }

  //
  // dst_of_dr_history_Connection
  //
  dr_history_Connection HistoryQosPolicy_Impl::dst_of_dr_history_Connection (void) const
  {
    return this->in_connections <dr_history_Connection> ("dst").first ();
  }

  //
  // dst_of_dw_history_Connection
  //
  size_t HistoryQosPolicy_Impl::dst_of_dw_history_Connection (std::vector <dw_history_Connection> & items) const
  {
    return this->in_connections <dw_history_Connection> (items);
  }

  //
  // has_dst_of_dw_history_Connection
  //
  bool HistoryQosPolicy_Impl::has_dst_of_dw_history_Connection (void) const
  {
    return this->in_connections <dw_history_Connection> ("dst").count () == 1;
  }

  //
  // dst_of_dw_history_Connection
  //
  dw_history_Connection HistoryQosPolicy_Impl::dst_of_dw_history_Connection (void) const
  {
    return this->in_connections <dw_history_Connection> ("dst").first ();
  }

  //
  // dst_of_topic_history_Connection
  //
  size_t HistoryQosPolicy_Impl::dst_of_topic_history_Connection (std::vector <topic_history_Connection> & items) const
  {
    return this->in_connections <topic_history_Connection> (items);
  }

  //
  // has_dst_of_topic_history_Connection
  //
  bool HistoryQosPolicy_Impl::has_dst_of_topic_history_Connection (void) const
  {
    return this->in_connections <topic_history_Connection> ("dst").count () == 1;
  }

  //
  // dst_of_topic_history_Connection
  //
  topic_history_Connection HistoryQosPolicy_Impl::dst_of_topic_history_Connection (void) const
  {
    return this->in_connections <topic_history_Connection> ("dst").first ();
  }
}

