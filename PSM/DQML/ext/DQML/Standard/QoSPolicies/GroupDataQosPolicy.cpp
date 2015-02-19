// $Id$

#include "StdAfx.h"
#include "GroupDataQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "GroupDataQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/GroupDataQosPolicy/pub_groupdata_Connection.h"
#include "DQML/Standard/GroupDataQosPolicy/sub_groupdata_Connection.h"
#include "DQML/iCCM/PublisherSubscriberQos/PublisherQos.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string GroupDataQosPolicy_Impl::metaname ("GroupDataQosPolicy");

  //
  // is_abstract
  //
  const bool GroupDataQosPolicy_Impl::is_abstract = false;

  //
  // _create (const PublisherQos_in)
  //
  GroupDataQosPolicy GroupDataQosPolicy_Impl::_create (const PublisherQos_in parent)
  {
    return ::GAME::Mga::create < GroupDataQosPolicy > (parent, GroupDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const SubscriberQos_in)
  //
  GroupDataQosPolicy GroupDataQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create < GroupDataQosPolicy > (parent, GroupDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  GroupDataQosPolicy GroupDataQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < GroupDataQosPolicy > (parent, GroupDataQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void GroupDataQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_GroupDataQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_PublisherQos
  //
  PublisherQos GroupDataQosPolicy_Impl::parent_PublisherQos (void)
  {
    return PublisherQos::_narrow (this->parent ());
  }

  //
  // parent_SubscriberQos
  //
  SubscriberQos GroupDataQosPolicy_Impl::parent_SubscriberQos (void)
  {
    return SubscriberQos::_narrow (this->parent ());
  }

  //
  // dst_of_pub_groupdata_Connection
  //
  size_t GroupDataQosPolicy_Impl::dst_of_pub_groupdata_Connection (std::vector <pub_groupdata_Connection> & items) const
  {
    return this->in_connections <pub_groupdata_Connection> (items);
  }

  //
  // has_dst_of_pub_groupdata_Connection
  //
  bool GroupDataQosPolicy_Impl::has_dst_of_pub_groupdata_Connection (void) const
  {
    return this->in_connections <pub_groupdata_Connection> ("dst").count () == 1;
  }

  //
  // dst_of_pub_groupdata_Connection
  //
  pub_groupdata_Connection GroupDataQosPolicy_Impl::dst_of_pub_groupdata_Connection (void) const
  {
    return this->in_connections <pub_groupdata_Connection> ("dst").first ();
  }

  //
  // dst_of_sub_groupdata_Connection
  //
  size_t GroupDataQosPolicy_Impl::dst_of_sub_groupdata_Connection (std::vector <sub_groupdata_Connection> & items) const
  {
    return this->in_connections <sub_groupdata_Connection> (items);
  }

  //
  // has_dst_of_sub_groupdata_Connection
  //
  bool GroupDataQosPolicy_Impl::has_dst_of_sub_groupdata_Connection (void) const
  {
    return this->in_connections <sub_groupdata_Connection> ("dst").count () == 1;
  }

  //
  // dst_of_sub_groupdata_Connection
  //
  sub_groupdata_Connection GroupDataQosPolicy_Impl::dst_of_sub_groupdata_Connection (void) const
  {
    return this->in_connections <sub_groupdata_Connection> ("dst").first ();
  }
}

