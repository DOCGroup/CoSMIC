// $Id$

#include "StdAfx.h"
#include "DestinationOrderQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DestinationOrderQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dw_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/topic_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dr_dstOrder_Connection.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DestinationOrderQosPolicy_Impl::metaname ("DestinationOrderQosPolicy");

  //
  // is_abstract
  //
  const bool DestinationOrderQosPolicy_Impl::is_abstract (0);

  //
  // _create (const DataReaderQos_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DestinationOrderQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DestinationOrderQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos DestinationOrderQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos DestinationOrderQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos DestinationOrderQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // dst_of_dw_dstOrder_Connection
  //
  size_t DestinationOrderQosPolicy_Impl::dst_of_dw_dstOrder_Connection (std::vector <dw_dstOrder_Connection> & items) const
  {
    return this->in_connections <dw_dstOrder_Connection> (items);
  }

  //
  // dst_of_dw_dstOrder_Connection
  //
  GAME::Mga::Collection_T <dw_dstOrder_Connection> DestinationOrderQosPolicy_Impl::dst_of_dw_dstOrder_Connection (void) const
  {
    return this->in_connections <dw_dstOrder_Connection> ("dst");
  }

  //
  // dst_of_topic_dstOrder_Connection
  //
  size_t DestinationOrderQosPolicy_Impl::dst_of_topic_dstOrder_Connection (std::vector <topic_dstOrder_Connection> & items) const
  {
    return this->in_connections <topic_dstOrder_Connection> (items);
  }

  //
  // dst_of_topic_dstOrder_Connection
  //
  GAME::Mga::Collection_T <topic_dstOrder_Connection> DestinationOrderQosPolicy_Impl::dst_of_topic_dstOrder_Connection (void) const
  {
    return this->in_connections <topic_dstOrder_Connection> ("dst");
  }

  //
  // dst_of_dr_dstOrder_Connection
  //
  size_t DestinationOrderQosPolicy_Impl::dst_of_dr_dstOrder_Connection (std::vector <dr_dstOrder_Connection> & items) const
  {
    return this->in_connections <dr_dstOrder_Connection> (items);
  }

  //
  // dst_of_dr_dstOrder_Connection
  //
  GAME::Mga::Collection_T <dr_dstOrder_Connection> DestinationOrderQosPolicy_Impl::dst_of_dr_dstOrder_Connection (void) const
  {
    return this->in_connections <dr_dstOrder_Connection> ("dst");
  }
}

