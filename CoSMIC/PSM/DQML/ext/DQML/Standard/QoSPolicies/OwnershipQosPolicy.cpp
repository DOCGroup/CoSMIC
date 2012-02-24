// $Id$

#include "StdAfx.h"
#include "OwnershipQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "OwnershipQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/OwnershipQosPolicy/dr_ownership_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/topic_ownership_Connection.h"
#include "DQML/Standard/OwnershipQosPolicy/dw_ownership_Connection.h"
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
  const std::string OwnershipQosPolicy_Impl::metaname ("OwnershipQosPolicy");

  //
  // _create (const TopicQos_in)
  //
  OwnershipQosPolicy OwnershipQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < OwnershipQosPolicy > (parent, OwnershipQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataWriterQos_in)
  //
  OwnershipQosPolicy OwnershipQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < OwnershipQosPolicy > (parent, OwnershipQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  OwnershipQosPolicy OwnershipQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < OwnershipQosPolicy > (parent, OwnershipQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  OwnershipQosPolicy OwnershipQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < OwnershipQosPolicy > (parent, OwnershipQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void OwnershipQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_OwnershipQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dr_ownership_Connection
  //
  size_t OwnershipQosPolicy_Impl::dst_dr_ownership_Connection (std::vector <dr_ownership_Connection> & items) const
  {
    return this->in_connections <dr_ownership_Connection> (items);
  }

  //
  // dst_topic_ownership_Connection
  //
  size_t OwnershipQosPolicy_Impl::dst_topic_ownership_Connection (std::vector <topic_ownership_Connection> & items) const
  {
    return this->in_connections <topic_ownership_Connection> (items);
  }

  //
  // dst_dw_ownership_Connection
  //
  size_t OwnershipQosPolicy_Impl::dst_dw_ownership_Connection (std::vector <dw_ownership_Connection> & items) const
  {
    return this->in_connections <dw_ownership_Connection> (items);
  }
}
