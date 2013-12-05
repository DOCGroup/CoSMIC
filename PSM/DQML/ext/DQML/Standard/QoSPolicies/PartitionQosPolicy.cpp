// $Id$

#include "StdAfx.h"
#include "PartitionQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "PartitionQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/PartitionQosPolicy/pub_part_Connection.h"
#include "DQML/Standard/PartitionQosPolicy/sub_part_Connection.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string PartitionQosPolicy_Impl::metaname ("PartitionQosPolicy");

  //
  // _create (const PublisherQos_in)
  //
  PartitionQosPolicy PartitionQosPolicy_Impl::_create (const PublisherQos_in parent)
  {
    return ::GAME::Mga::create_object < PartitionQosPolicy > (parent, PartitionQosPolicy_Impl::metaname);
  }

  //
  // _create (const SubscriberQos_in)
  //
  PartitionQosPolicy PartitionQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create_object < PartitionQosPolicy > (parent, PartitionQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  PartitionQosPolicy PartitionQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < PartitionQosPolicy > (parent, PartitionQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void PartitionQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PartitionQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_pub_part_Connection
  //
  size_t PartitionQosPolicy_Impl::dst_pub_part_Connection (std::vector <pub_part_Connection> & items) const
  {
    return this->in_connections <pub_part_Connection> (items);
  }

  //
  // dst_sub_part_Connection
  //
  size_t PartitionQosPolicy_Impl::dst_sub_part_Connection (std::vector <sub_part_Connection> & items) const
  {
    return this->in_connections <sub_part_Connection> (items);
  }
}

