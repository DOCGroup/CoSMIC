// $Id$

#include "StdAfx.h"
#include "TopicDataQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "TopicDataQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "DQML/Standard/TopicDataQosPolicy/topic_topicdata_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool TopicDataQosPolicy_Impl::is_abstract = false;

  //
  // _create (const TopicQos_in)
  //
  TopicDataQosPolicy TopicDataQosPolicy_Impl::_create (const TopicQos_in parent)
  {
    return ::GAME::Mga::create < TopicDataQosPolicy > (parent, TopicDataQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  TopicDataQosPolicy TopicDataQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < TopicDataQosPolicy > (parent, TopicDataQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void TopicDataQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopicDataQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_TopicQos
  //
  TopicQos TopicDataQosPolicy_Impl::parent_TopicQos (void)
  {
    return TopicQos::_narrow (this->parent ());
  }

  //
  // dst_of_topic_topicdata_Connection
  //
  size_t TopicDataQosPolicy_Impl::dst_of_topic_topicdata_Connection (std::vector <topic_topicdata_Connection> & items) const
  {
    return this->in_connections <topic_topicdata_Connection> (items);
  }

  //
  // dst_of_topic_topicdata_Connection
  //
  GAME::Mga::Collection_T <topic_topicdata_Connection> TopicDataQosPolicy_Impl::dst_of_topic_topicdata_Connection (void) const
  {
    return this->in_connections <topic_topicdata_Connection> ("dst");
  }
}

