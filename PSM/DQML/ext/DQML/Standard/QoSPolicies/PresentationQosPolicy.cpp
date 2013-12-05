// $Id$

#include "StdAfx.h"
#include "PresentationQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "PresentationQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/PresentationQosPolicy/pub_presqos_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/sub_presqos_Connection.h"
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
  const std::string PresentationQosPolicy_Impl::metaname ("PresentationQosPolicy");

  //
  // _create (const PublisherQos_in)
  //
  PresentationQosPolicy PresentationQosPolicy_Impl::_create (const PublisherQos_in parent)
  {
    return ::GAME::Mga::create_object < PresentationQosPolicy > (parent, PresentationQosPolicy_Impl::metaname);
  }

  //
  // _create (const SubscriberQos_in)
  //
  PresentationQosPolicy PresentationQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create_object < PresentationQosPolicy > (parent, PresentationQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  PresentationQosPolicy PresentationQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < PresentationQosPolicy > (parent, PresentationQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void PresentationQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PresentationQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_pub_presqos_Connection
  //
  size_t PresentationQosPolicy_Impl::dst_pub_presqos_Connection (std::vector <pub_presqos_Connection> & items) const
  {
    return this->in_connections <pub_presqos_Connection> (items);
  }

  //
  // dst_sub_presqos_Connection
  //
  size_t PresentationQosPolicy_Impl::dst_sub_presqos_Connection (std::vector <sub_presqos_Connection> & items) const
  {
    return this->in_connections <sub_presqos_Connection> (items);
  }
}

