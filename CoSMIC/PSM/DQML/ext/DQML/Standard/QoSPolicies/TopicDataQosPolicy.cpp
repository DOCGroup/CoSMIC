// $Id$

#include "StdAfx.h"
#include "TopicDataQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "TopicDataQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/TopicDataQosPolicy/topic_topicdata_Connection.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TopicDataQosPolicy_Impl::metaname ("TopicDataQosPolicy");

  //
  // _create (const TopicQos_in)
  //
  TopicDataQosPolicy TopicDataQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create_object < TopicDataQosPolicy > (parent, TopicDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  TopicDataQosPolicy TopicDataQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < TopicDataQosPolicy > (parent, TopicDataQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void TopicDataQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TopicDataQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_topic_topicdata_Connection
  //
  size_t TopicDataQosPolicy_Impl::dst_topic_topicdata_Connection (std::vector <topic_topicdata_Connection> & items) const
  {
    return this->in_connections <topic_topicdata_Connection> (items);
  }
}

