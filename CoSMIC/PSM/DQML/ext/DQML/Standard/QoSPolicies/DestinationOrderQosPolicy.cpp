// $Id$

#include "StdAfx.h"
#include "DestinationOrderQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DestinationOrderQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dr_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/topic_dstOrder_Connection.h"
#include "DQML/Standard/DestinationOrderQosPolicy/dw_dstOrder_Connection.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
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
  // _create (const TopicQos_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DestinationOrderQosPolicy DestinationOrderQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < DestinationOrderQosPolicy > (parent, DestinationOrderQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DestinationOrderQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DestinationOrderQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dr_dstOrder_Connection
  //
  size_t DestinationOrderQosPolicy_Impl::dst_dr_dstOrder_Connection (std::vector <dr_dstOrder_Connection> & items) const
  {
    return this->in_connections <dr_dstOrder_Connection> (items);
  }

  //
  // dst_topic_dstOrder_Connection
  //
  size_t DestinationOrderQosPolicy_Impl::dst_topic_dstOrder_Connection (std::vector <topic_dstOrder_Connection> & items) const
  {
    return this->in_connections <topic_dstOrder_Connection> (items);
  }

  //
  // dst_dw_dstOrder_Connection
  //
  size_t DestinationOrderQosPolicy_Impl::dst_dw_dstOrder_Connection (std::vector <dw_dstOrder_Connection> & items) const
  {
    return this->in_connections <dw_dstOrder_Connection> (items);
  }
}

