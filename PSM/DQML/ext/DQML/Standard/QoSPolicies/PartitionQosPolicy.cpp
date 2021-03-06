#include "StdAfx.h"
#include "PartitionQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "PartitionQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/PartitionQosPolicy/pub_part_Connection.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/Standard/PartitionQosPolicy/sub_part_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool PartitionQosPolicy_Impl::is_abstract = false;

  //
  // _create (const PublisherQos_in)
  //
  PartitionQosPolicy PartitionQosPolicy_Impl::_create (const PublisherQos_in parent)
  {
    return ::GAME::Mga::create < PartitionQosPolicy > (parent, PartitionQosPolicy_Impl::metaname);
  }

  //
  // _create (const SubscriberQos_in)
  //
  PartitionQosPolicy PartitionQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create < PartitionQosPolicy > (parent, PartitionQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  PartitionQosPolicy PartitionQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < PartitionQosPolicy > (parent, PartitionQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void PartitionQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PartitionQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_PublisherQos
  //
  PublisherQos PartitionQosPolicy_Impl::parent_PublisherQos (void)
  {
    return PublisherQos::_narrow (this->parent ());
  }

  //
  // parent_SubscriberQos
  //
  SubscriberQos PartitionQosPolicy_Impl::parent_SubscriberQos (void)
  {
    return SubscriberQos::_narrow (this->parent ());
  }

  //
  // dst_of_pub_part_Connection
  //
  size_t PartitionQosPolicy_Impl::dst_of_pub_part_Connection (std::vector <pub_part_Connection> & items) const
  {
    return this->in_connections <pub_part_Connection> (items);
  }

  //
  // dst_of_pub_part_Connection
  //
  GAME::Mga::Collection_T <pub_part_Connection> PartitionQosPolicy_Impl::dst_of_pub_part_Connection (void) const
  {
    return this->in_connections <pub_part_Connection> ("dst");
  }

  //
  // dst_of_sub_part_Connection
  //
  size_t PartitionQosPolicy_Impl::dst_of_sub_part_Connection (std::vector <sub_part_Connection> & items) const
  {
    return this->in_connections <sub_part_Connection> (items);
  }

  //
  // dst_of_sub_part_Connection
  //
  GAME::Mga::Collection_T <sub_part_Connection> PartitionQosPolicy_Impl::dst_of_sub_part_Connection (void) const
  {
    return this->in_connections <sub_part_Connection> ("dst");
  }
}

