// $Id$

#include "StdAfx.h"
#include "Publisher.h"

#if !defined (__GAME_INLINE__)
#include "Publisher.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/PartitionQosPolicy/pub_part_Connection.h"
#include "DQML/Standard/Main/dw_pub_Connection.h"
#include "DQML/Standard/GroupDataQosPolicy/pub_groupdata_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/pub_presqos_Connection.h"
#include "DQML/Standard/Main/dp_pub_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/pub_entityfactory_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string Publisher_Impl::metaname ("Publisher");

  //
  // _create (const DDSQoS_in)
  //
  Publisher Publisher_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < Publisher > (parent, Publisher_Impl::metaname);
  }

  //
  // accept
  //
  void Publisher_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Publisher (this);
    else
      v->visit_Model (this);
  }

  //
  // src_pub_part_Connection
  //
  size_t Publisher_Impl::src_pub_part_Connection (std::vector <pub_part_Connection> & items) const
  {
    return this->in_connections <pub_part_Connection> (items);
  }

  //
  // src_dw_pub_Connection
  //
  size_t Publisher_Impl::src_dw_pub_Connection (std::vector <dw_pub_Connection> & items) const
  {
    return this->in_connections <dw_pub_Connection> (items);
  }

  //
  // src_pub_groupdata_Connection
  //
  size_t Publisher_Impl::src_pub_groupdata_Connection (std::vector <pub_groupdata_Connection> & items) const
  {
    return this->in_connections <pub_groupdata_Connection> (items);
  }

  //
  // src_pub_presqos_Connection
  //
  size_t Publisher_Impl::src_pub_presqos_Connection (std::vector <pub_presqos_Connection> & items) const
  {
    return this->in_connections <pub_presqos_Connection> (items);
  }

  //
  // src_pub_entityfactory_Connection
  //
  size_t Publisher_Impl::src_pub_entityfactory_Connection (std::vector <pub_entityfactory_Connection> & items) const
  {
    return this->in_connections <pub_entityfactory_Connection> (items);
  }

  //
  // dst_dp_pub_Connection
  //
  size_t Publisher_Impl::dst_dp_pub_Connection (std::vector <dp_pub_Connection> & items) const
  {
    return this->in_connections <dp_pub_Connection> (items);
  }
}

