// $Id$

#include "StdAfx.h"
#include "TransportPriorityQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "TransportPriorityQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/Standard/TransportPriorityQosPolicy/topic_transpri_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/dw_transpri_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TransportPriorityQosPolicy_Impl::metaname ("TransportPriorityQosPolicy");

  //
  // is_abstract
  //
  const bool TransportPriorityQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataWriterQos_in)
  //
  TransportPriorityQosPolicy TransportPriorityQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < TransportPriorityQosPolicy > (parent, TransportPriorityQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  TransportPriorityQosPolicy TransportPriorityQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < TransportPriorityQosPolicy > (parent, TransportPriorityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  TransportPriorityQosPolicy TransportPriorityQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < TransportPriorityQosPolicy > (parent, TransportPriorityQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void TransportPriorityQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TransportPriorityQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos TransportPriorityQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos TransportPriorityQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_of_topic_transpri_Connection
  //
  size_t TransportPriorityQosPolicy_Impl::dst_of_topic_transpri_Connection (std::vector <topic_transpri_Connection> & items) const
  {
    return this->in_connections <topic_transpri_Connection> (items);
  }

  //
  // dst_of_topic_transpri_Connection
  //
  GAME::Mga::Collection_T <topic_transpri_Connection> TransportPriorityQosPolicy_Impl::dst_of_topic_transpri_Connection (void) const
  {
    return this->in_connections <topic_transpri_Connection> ("dst");
  }

  //
  // dst_of_dw_transpri_Connection
  //
  size_t TransportPriorityQosPolicy_Impl::dst_of_dw_transpri_Connection (std::vector <dw_transpri_Connection> & items) const
  {
    return this->in_connections <dw_transpri_Connection> (items);
  }

  //
  // dst_of_dw_transpri_Connection
  //
  GAME::Mga::Collection_T <dw_transpri_Connection> TransportPriorityQosPolicy_Impl::dst_of_dw_transpri_Connection (void) const
  {
    return this->in_connections <dw_transpri_Connection> ("dst");
  }
}

