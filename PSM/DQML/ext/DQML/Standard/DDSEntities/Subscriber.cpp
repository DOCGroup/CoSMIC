// $Id$

#include "StdAfx.h"
#include "Subscriber.h"

#if !defined (__GAME_INLINE__)
#include "Subscriber.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/GroupDataQosPolicy/sub_groupdata_Connection.h"
#include "DQML/Standard/Main/dr_sub_Connection.h"
#include "DQML/Standard/Main/dp_sub_Connection.h"
#include "DQML/Standard/PartitionQosPolicy/sub_part_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/sub_presqos_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/sub_entityfactory_Connection.h"
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
  // _create (const DDSQoS_in)
  //
  Subscriber Subscriber_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < Subscriber > (parent, Subscriber_Impl::metaname);
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
  // src_sub_groupdata_Connection
  //
  size_t Subscriber_Impl::src_sub_groupdata_Connection (std::vector <sub_groupdata_Connection> & items) const
  {
    return this->in_connections <sub_groupdata_Connection> (items);
  }

  //
  // src_dr_sub_Connection
  //
  size_t Subscriber_Impl::src_dr_sub_Connection (std::vector <dr_sub_Connection> & items) const
  {
    return this->in_connections <dr_sub_Connection> (items);
  }

  //
  // src_sub_part_Connection
  //
  size_t Subscriber_Impl::src_sub_part_Connection (std::vector <sub_part_Connection> & items) const
  {
    return this->in_connections <sub_part_Connection> (items);
  }

  //
  // src_sub_presqos_Connection
  //
  size_t Subscriber_Impl::src_sub_presqos_Connection (std::vector <sub_presqos_Connection> & items) const
  {
    return this->in_connections <sub_presqos_Connection> (items);
  }

  //
  // src_sub_entityfactory_Connection
  //
  size_t Subscriber_Impl::src_sub_entityfactory_Connection (std::vector <sub_entityfactory_Connection> & items) const
  {
    return this->in_connections <sub_entityfactory_Connection> (items);
  }

  //
  // dst_dp_sub_Connection
  //
  size_t Subscriber_Impl::dst_dp_sub_Connection (std::vector <dp_sub_Connection> & items) const
  {
    return this->in_connections <dp_sub_Connection> (items);
  }
}

