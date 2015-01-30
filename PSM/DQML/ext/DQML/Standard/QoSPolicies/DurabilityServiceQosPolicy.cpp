// $Id$

#include "StdAfx.h"
#include "DurabilityServiceQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DurabilityServiceQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/topic_dursvc_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/dw_dursvc_Connection.h"
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
  const std::string DurabilityServiceQosPolicy_Impl::metaname ("DurabilityServiceQosPolicy");

  //
  // _create (const TopicQos_in)
  //
  DurabilityServiceQosPolicy DurabilityServiceQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < DurabilityServiceQosPolicy > (parent, DurabilityServiceQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DurabilityServiceQosPolicy DurabilityServiceQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DurabilityServiceQosPolicy > (parent, DurabilityServiceQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DurabilityServiceQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DurabilityServiceQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_TopicQos
  //
  TopicQos DurabilityServiceQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_of_topic_dursvc_Connection
  //
  size_t DurabilityServiceQosPolicy_Impl::dst_of_topic_dursvc_Connection (std::vector <topic_dursvc_Connection> & items) const
  {
    return this->in_connections <topic_dursvc_Connection> (items);
  }

  //
  // dst_of_topic_dursvc_Connection
  //
  GAME::Mga::Collection_T <topic_dursvc_Connection> DurabilityServiceQosPolicy_Impl::dst_of_topic_dursvc_Connection (void) const
  {
    return this->in_connections <topic_dursvc_Connection> ("dst");
  }

  //
  // dst_of_dw_dursvc_Connection
  //
  size_t DurabilityServiceQosPolicy_Impl::dst_of_dw_dursvc_Connection (std::vector <dw_dursvc_Connection> & items) const
  {
    return this->in_connections <dw_dursvc_Connection> (items);
  }

  //
  // dst_of_dw_dursvc_Connection
  //
  GAME::Mga::Collection_T <dw_dursvc_Connection> DurabilityServiceQosPolicy_Impl::dst_of_dw_dursvc_Connection (void) const
  {
    return this->in_connections <dw_dursvc_Connection> ("dst");
  }
}

