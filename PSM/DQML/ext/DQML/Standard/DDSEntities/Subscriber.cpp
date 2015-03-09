// $Id$

#include "StdAfx.h"
#include "Subscriber.h"

#if !defined (__GAME_INLINE__)
#include "Subscriber.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/PresentationQosPolicy/sub_presqos_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/Main/dp_sub_Connection.h"
#include "DQML/Standard/GroupDataQosPolicy/sub_groupdata_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/sub_entityfactory_Connection.h"
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
  const std::string Subscriber_Impl::metaname ("Subscriber");

  //
  // is_abstract
  //
  const bool Subscriber_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in)
  //
  Subscriber Subscriber_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < Subscriber > (parent, Subscriber_Impl::metaname);
  }

  //
  // accept
  //
  void Subscriber_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Subscriber (this);
    else
      v->visit_Model (this);
  }

  //
  // src_of_sub_presqos_Connection
  //
  size_t Subscriber_Impl::src_of_sub_presqos_Connection (std::vector <sub_presqos_Connection> & items) const
  {
    return this->in_connections <sub_presqos_Connection> (items);
  }

  //
  // has_src_of_sub_presqos_Connection
  //
  bool Subscriber_Impl::has_src_of_sub_presqos_Connection (void) const
  {
    return this->in_connections <sub_presqos_Connection> ("src").count () == 1;
  }

  //
  // src_of_sub_presqos_Connection
  //
  sub_presqos_Connection Subscriber_Impl::src_of_sub_presqos_Connection (void) const
  {
    return this->in_connections <sub_presqos_Connection> ("src").first ();
  }

  //
  // src_of_dr_sub_Connection
  //
  size_t Subscriber_Impl::src_of_dr_sub_Connection (std::vector <dr_sub_Connection> & items) const
  {
    return this->in_connections <dr_sub_Connection> (items);
  }

  //
  // src_of_dr_sub_Connection
  //
  GAME::Mga::Collection_T <dr_sub_Connection> Subscriber_Impl::src_of_dr_sub_Connection (void) const
  {
    return this->in_connections <dr_sub_Connection> ("src");
  }

  //
  // src_of_sub_groupdata_Connection
  //
  size_t Subscriber_Impl::src_of_sub_groupdata_Connection (std::vector <sub_groupdata_Connection> & items) const
  {
    return this->in_connections <sub_groupdata_Connection> (items);
  }

  //
  // has_src_of_sub_groupdata_Connection
  //
  bool Subscriber_Impl::has_src_of_sub_groupdata_Connection (void) const
  {
    return this->in_connections <sub_groupdata_Connection> ("src").count () == 1;
  }

  //
  // src_of_sub_groupdata_Connection
  //
  sub_groupdata_Connection Subscriber_Impl::src_of_sub_groupdata_Connection (void) const
  {
    return this->in_connections <sub_groupdata_Connection> ("src").first ();
  }

  //
  // src_of_sub_entityfactory_Connection
  //
  size_t Subscriber_Impl::src_of_sub_entityfactory_Connection (std::vector <sub_entityfactory_Connection> & items) const
  {
    return this->in_connections <sub_entityfactory_Connection> (items);
  }

  //
  // has_src_of_sub_entityfactory_Connection
  //
  bool Subscriber_Impl::has_src_of_sub_entityfactory_Connection (void) const
  {
    return this->in_connections <sub_entityfactory_Connection> ("src").count () == 1;
  }

  //
  // src_of_sub_entityfactory_Connection
  //
  sub_entityfactory_Connection Subscriber_Impl::src_of_sub_entityfactory_Connection (void) const
  {
    return this->in_connections <sub_entityfactory_Connection> ("src").first ();
  }

  //
  // src_of_sub_part_Connection
  //
  size_t Subscriber_Impl::src_of_sub_part_Connection (std::vector <sub_part_Connection> & items) const
  {
    return this->in_connections <sub_part_Connection> (items);
  }

  //
  // has_src_of_sub_part_Connection
  //
  bool Subscriber_Impl::has_src_of_sub_part_Connection (void) const
  {
    return this->in_connections <sub_part_Connection> ("src").count () == 1;
  }

  //
  // src_of_sub_part_Connection
  //
  sub_part_Connection Subscriber_Impl::src_of_sub_part_Connection (void) const
  {
    return this->in_connections <sub_part_Connection> ("src").first ();
  }

  //
  // dst_of_dp_sub_Connection
  //
  size_t Subscriber_Impl::dst_of_dp_sub_Connection (std::vector <dp_sub_Connection> & items) const
  {
    return this->in_connections <dp_sub_Connection> (items);
  }

  //
  // dst_of_dp_sub_Connection
  //
  dp_sub_Connection Subscriber_Impl::dst_of_dp_sub_Connection (void) const
  {
    return this->in_connections <dp_sub_Connection> ("dst").first ();
  }
}

