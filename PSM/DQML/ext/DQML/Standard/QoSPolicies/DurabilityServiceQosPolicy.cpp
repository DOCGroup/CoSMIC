// $Id$

#include "StdAfx.h"
#include "DurabilityServiceQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "DurabilityServiceQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/topic_dursvc_Connection.h"
#include "DQML/Standard/DurabilityServiceQosPolicy/dw_dursvc_Connection.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
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
    return ::GAME::Mga::create_object < DurabilityServiceQosPolicy > (parent, DurabilityServiceQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  DurabilityServiceQosPolicy DurabilityServiceQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < DurabilityServiceQosPolicy > (parent, DurabilityServiceQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void DurabilityServiceQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DurabilityServiceQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_topic_dursvc_Connection
  //
  size_t DurabilityServiceQosPolicy_Impl::dst_topic_dursvc_Connection (std::vector <topic_dursvc_Connection> & items) const
  {
    return this->in_connections <topic_dursvc_Connection> (items);
  }

  //
  // dst_dw_dursvc_Connection
  //
  size_t DurabilityServiceQosPolicy_Impl::dst_dw_dursvc_Connection (std::vector <dw_dursvc_Connection> & items) const
  {
    return this->in_connections <dw_dursvc_Connection> (items);
  }
}

