// $Id$

#include "StdAfx.h"
#include "ReliabilityQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ReliabilityQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/ReliabilityQosPolicy/dw_reliability_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/topic_reliability_Connection.h"
#include "DQML/Standard/ReliabilityQosPolicy/dr_reliability_Connection.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string ReliabilityQosPolicy_Impl::metaname ("ReliabilityQosPolicy");

  //
  // _create (const DataReaderQos_in)
  //
  ReliabilityQosPolicy ReliabilityQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < ReliabilityQosPolicy > (parent, ReliabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  ReliabilityQosPolicy ReliabilityQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < ReliabilityQosPolicy > (parent, ReliabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  ReliabilityQosPolicy ReliabilityQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < ReliabilityQosPolicy > (parent, ReliabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  ReliabilityQosPolicy ReliabilityQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < ReliabilityQosPolicy > (parent, ReliabilityQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void ReliabilityQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ReliabilityQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos ReliabilityQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos ReliabilityQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos ReliabilityQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_dw_reliability_Connection
  //
  size_t ReliabilityQosPolicy_Impl::dst_dw_reliability_Connection (std::vector <dw_reliability_Connection> & items) const
  {
    return this->in_connections <dw_reliability_Connection> (items);
  }

  //
  // dst_topic_reliability_Connection
  //
  size_t ReliabilityQosPolicy_Impl::dst_topic_reliability_Connection (std::vector <topic_reliability_Connection> & items) const
  {
    return this->in_connections <topic_reliability_Connection> (items);
  }

  //
  // dst_dr_reliability_Connection
  //
  size_t ReliabilityQosPolicy_Impl::dst_dr_reliability_Connection (std::vector <dr_reliability_Connection> & items) const
  {
    return this->in_connections <dr_reliability_Connection> (items);
  }
}

