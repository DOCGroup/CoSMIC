// $Id$

#include "StdAfx.h"
#include "ResourceLimitsQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ResourceLimitsQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dr_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/topic_res_Connection.h"
#include "DQML/Standard/ResourceLimitsQosPolicy/dw_res_Connection.h"
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
  const std::string ResourceLimitsQosPolicy_Impl::metaname ("ResourceLimitsQosPolicy");

  //
  // _create (const TopicQos_in)
  //
  ResourceLimitsQosPolicy ResourceLimitsQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < ResourceLimitsQosPolicy > (parent, ResourceLimitsQosPolicy_Impl::metaname);
  }

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
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ResourceLimitsQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dr_res_Connection
  //
  size_t ResourceLimitsQosPolicy_Impl::dst_dr_res_Connection (std::vector <dr_res_Connection> & items) const
  {
    return this->in_connections <dr_res_Connection> (items);
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
}

