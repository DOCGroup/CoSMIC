// $Id$

#include "StdAfx.h"
#include "TransportPriorityQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "TransportPriorityQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/TransportPriorityQosPolicy/dw_transpri_Connection.h"
#include "DQML/Standard/TransportPriorityQosPolicy/topic_transpri_Connection.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
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
  // _create (const TopicQos_in)
  //
  TransportPriorityQosPolicy TransportPriorityQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < TransportPriorityQosPolicy > (parent, TransportPriorityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  TransportPriorityQosPolicy TransportPriorityQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < TransportPriorityQosPolicy > (parent, TransportPriorityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  TransportPriorityQosPolicy TransportPriorityQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < TransportPriorityQosPolicy > (parent, TransportPriorityQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void TransportPriorityQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TransportPriorityQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dw_transpri_Connection
  //
  size_t TransportPriorityQosPolicy_Impl::dst_dw_transpri_Connection (std::vector <dw_transpri_Connection> & items) const
  {
    return this->in_connections <dw_transpri_Connection> (items);
  }

  //
  // dst_topic_transpri_Connection
  //
  size_t TransportPriorityQosPolicy_Impl::dst_topic_transpri_Connection (std::vector <topic_transpri_Connection> & items) const
  {
    return this->in_connections <topic_transpri_Connection> (items);
  }
}

