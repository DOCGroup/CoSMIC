// $Id$

#include "StdAfx.h"
#include "LifespanQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "LifespanQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/LifespanQosPolicy/dw_lifespan_Connection.h"
#include "DQML/Standard/LifespanQosPolicy/topic_lifespan_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
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
  const std::string LifespanQosPolicy_Impl::metaname ("LifespanQosPolicy");

  //
  // _create (const DataWriterQos_in)
  //
  LifespanQosPolicy LifespanQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < LifespanQosPolicy > (parent, LifespanQosPolicy_Impl::metaname);
  }

  //
  // _create (const TopicQos_in)
  //
  LifespanQosPolicy LifespanQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < LifespanQosPolicy > (parent, LifespanQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  LifespanQosPolicy LifespanQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < LifespanQosPolicy > (parent, LifespanQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void LifespanQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LifespanQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos LifespanQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_TopicQos
  //
  TopicQos LifespanQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_dw_lifespan_Connection
  //
  size_t LifespanQosPolicy_Impl::dst_dw_lifespan_Connection (std::vector <dw_lifespan_Connection> & items) const
  {
    return this->in_connections <dw_lifespan_Connection> (items);
  }

  //
  // dst_topic_lifespan_Connection
  //
  size_t LifespanQosPolicy_Impl::dst_topic_lifespan_Connection (std::vector <topic_lifespan_Connection> & items) const
  {
    return this->in_connections <topic_lifespan_Connection> (items);
  }
}

