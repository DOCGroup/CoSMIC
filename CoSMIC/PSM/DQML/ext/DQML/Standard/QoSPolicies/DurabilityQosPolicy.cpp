// $Id$

#include "StdAfx.h"
#include "DurabilityQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DurabilityQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DurabilityQosPolicy/dr_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/topic_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dw_durqos_Connection.h"
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
  const std::string DurabilityQosPolicy_Impl::metaname ("DurabilityQosPolicy");

  //
  // _create (const TopicQos_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DurabilityQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DurabilityQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dr_durqos_Connection
  //
  size_t DurabilityQosPolicy_Impl::dst_dr_durqos_Connection (std::vector <dr_durqos_Connection> & items) const
  {
    return this->in_connections <dr_durqos_Connection> (items);
  }

  //
  // dst_topic_durqos_Connection
  //
  size_t DurabilityQosPolicy_Impl::dst_topic_durqos_Connection (std::vector <topic_durqos_Connection> & items) const
  {
    return this->in_connections <topic_durqos_Connection> (items);
  }

  //
  // dst_dw_durqos_Connection
  //
  size_t DurabilityQosPolicy_Impl::dst_dw_durqos_Connection (std::vector <dw_durqos_Connection> & items) const
  {
    return this->in_connections <dw_durqos_Connection> (items);
  }
}
