// $Id$

#include "StdAfx.h"
#include "LivelinessQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "LivelinessQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/LivelinessQosPolicy/dw_liveliness_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/dr_liveliness_Connection.h"
#include "DQML/Standard/LivelinessQosPolicy/topic_liveliness_Connection.h"
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
  const std::string LivelinessQosPolicy_Impl::metaname ("LivelinessQosPolicy");

  //
  // _create (const DataReaderQos_in)
  //
  LivelinessQosPolicy LivelinessQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < LivelinessQosPolicy > (parent, LivelinessQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  LivelinessQosPolicy LivelinessQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < LivelinessQosPolicy > (parent, LivelinessQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  LivelinessQosPolicy LivelinessQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < LivelinessQosPolicy > (parent, LivelinessQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  LivelinessQosPolicy LivelinessQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < LivelinessQosPolicy > (parent, LivelinessQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void LivelinessQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LivelinessQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos LivelinessQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos LivelinessQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos LivelinessQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_dw_liveliness_Connection
  //
  size_t LivelinessQosPolicy_Impl::dst_dw_liveliness_Connection (std::vector <dw_liveliness_Connection> & items) const
  {
    return this->in_connections <dw_liveliness_Connection> (items);
  }

  //
  // dst_dr_liveliness_Connection
  //
  size_t LivelinessQosPolicy_Impl::dst_dr_liveliness_Connection (std::vector <dr_liveliness_Connection> & items) const
  {
    return this->in_connections <dr_liveliness_Connection> (items);
  }

  //
  // dst_topic_liveliness_Connection
  //
  size_t LivelinessQosPolicy_Impl::dst_topic_liveliness_Connection (std::vector <topic_liveliness_Connection> & items) const
  {
    return this->in_connections <topic_liveliness_Connection> (items);
  }
}

