#include "StdAfx.h"
#include "DurabilityQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DurabilityQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/Standard/DurabilityQosPolicy/dw_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/topic_durqos_Connection.h"
#include "DQML/Standard/DurabilityQosPolicy/dr_durqos_Connection.h"
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
  const std::string DurabilityQosPolicy_Impl::metaname ("DurabilityQosPolicy");

  //
  // is_abstract
  //
  const bool DurabilityQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataReaderQos_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DurabilityQosPolicy DurabilityQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DurabilityQosPolicy > (parent, DurabilityQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DurabilityQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DurabilityQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos DurabilityQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos DurabilityQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos DurabilityQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_of_dw_durqos_Connection
  //
  size_t DurabilityQosPolicy_Impl::dst_of_dw_durqos_Connection (std::vector <dw_durqos_Connection> & items) const
  {
    return this->in_connections <dw_durqos_Connection> (items);
  }

  //
  // dst_of_dw_durqos_Connection
  //
  GAME::Mga::Collection_T <dw_durqos_Connection> DurabilityQosPolicy_Impl::dst_of_dw_durqos_Connection (void) const
  {
    return this->in_connections <dw_durqos_Connection> ("dst");
  }

  //
  // dst_of_topic_durqos_Connection
  //
  size_t DurabilityQosPolicy_Impl::dst_of_topic_durqos_Connection (std::vector <topic_durqos_Connection> & items) const
  {
    return this->in_connections <topic_durqos_Connection> (items);
  }

  //
  // dst_of_topic_durqos_Connection
  //
  GAME::Mga::Collection_T <topic_durqos_Connection> DurabilityQosPolicy_Impl::dst_of_topic_durqos_Connection (void) const
  {
    return this->in_connections <topic_durqos_Connection> ("dst");
  }

  //
  // dst_of_dr_durqos_Connection
  //
  size_t DurabilityQosPolicy_Impl::dst_of_dr_durqos_Connection (std::vector <dr_durqos_Connection> & items) const
  {
    return this->in_connections <dr_durqos_Connection> (items);
  }

  //
  // dst_of_dr_durqos_Connection
  //
  GAME::Mga::Collection_T <dr_durqos_Connection> DurabilityQosPolicy_Impl::dst_of_dr_durqos_Connection (void) const
  {
    return this->in_connections <dr_durqos_Connection> ("dst");
  }
}

