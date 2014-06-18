// $Id$

#include "StdAfx.h"
#include "ResourceLimitsQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ResourceLimitsQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/topic_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dw_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dr_res_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
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
  const std::string ResourceLimitsQosPolicy_Impl::metaname ("ResourceLimitsQosPolicy");

  //
  // _create (const DataWriterQos_in)
  //
  ResourceLimitsQosPolicy ResourceLimitsQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < ResourceLimitsQosPolicy > (parent, ResourceLimitsQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  ResourceLimitsQosPolicy ResourceLimitsQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < ResourceLimitsQosPolicy > (parent, ResourceLimitsQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  ResourceLimitsQosPolicy ResourceLimitsQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < ResourceLimitsQosPolicy > (parent, ResourceLimitsQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  ResourceLimitsQosPolicy ResourceLimitsQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < ResourceLimitsQosPolicy > (parent, ResourceLimitsQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void ResourceLimitsQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ResourceLimitsQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos ResourceLimitsQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos ResourceLimitsQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos ResourceLimitsQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_topic_res_Connection
  //
  size_t ResourceLimitsQosPolicy_Impl::dst_topic_res_Connection (std::vector <topic_res_Connection> & items) const
  {
    return this->in_connections <topic_res_Connection> (items);
  }

  //
  // dst_dw_res_Connection
  //
  size_t ResourceLimitsQosPolicy_Impl::dst_dw_res_Connection (std::vector <dw_res_Connection> & items) const
  {
    return this->in_connections <dw_res_Connection> (items);
  }

  //
  // dst_dr_res_Connection
  //
  size_t ResourceLimitsQosPolicy_Impl::dst_dr_res_Connection (std::vector <dr_res_Connection> & items) const
  {
    return this->in_connections <dr_res_Connection> (items);
  }
}

