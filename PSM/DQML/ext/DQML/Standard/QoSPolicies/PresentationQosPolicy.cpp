#include "StdAfx.h"
#include "PresentationQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "PresentationQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/PresentationQosPolicy/sub_presqos_Connection.h"
#include "DQML/Standard/PresentationQosPolicy/pub_presqos_Connection.h"
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
  const std::string PresentationQosPolicy_Impl::metaname ("PresentationQosPolicy");

  //
  // is_abstract
  //
  const bool PresentationQosPolicy_Impl::is_abstract = false;

  //
  // _create (const PublisherQos_in)
  //
  PresentationQosPolicy PresentationQosPolicy_Impl::_create (const PublisherQos_in parent)
  {
    return ::GAME::Mga::create < PresentationQosPolicy > (parent, PresentationQosPolicy_Impl::metaname);
  }

  //
  // _create (const SubscriberQos_in)
  //
  PresentationQosPolicy PresentationQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create < PresentationQosPolicy > (parent, PresentationQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  PresentationQosPolicy PresentationQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < PresentationQosPolicy > (parent, PresentationQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void PresentationQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PresentationQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_PublisherQos
  //
  PublisherQos PresentationQosPolicy_Impl::parent_PublisherQos (void)
  {
    return PublisherQos::_narrow (this->parent ());
  }

  //
  // parent_SubscriberQos
  //
  SubscriberQos PresentationQosPolicy_Impl::parent_SubscriberQos (void)
  {
    return SubscriberQos::_narrow (this->parent ());
  }

  //
  // dst_of_sub_presqos_Connection
  //
  size_t PresentationQosPolicy_Impl::dst_of_sub_presqos_Connection (std::vector <sub_presqos_Connection> & items) const
  {
    return this->in_connections <sub_presqos_Connection> (items);
  }

  //
  // dst_of_sub_presqos_Connection
  //
  GAME::Mga::Collection_T <sub_presqos_Connection> PresentationQosPolicy_Impl::dst_of_sub_presqos_Connection (void) const
  {
    return this->in_connections <sub_presqos_Connection> ("dst");
  }

  //
  // dst_of_pub_presqos_Connection
  //
  size_t PresentationQosPolicy_Impl::dst_of_pub_presqos_Connection (std::vector <pub_presqos_Connection> & items) const
  {
    return this->in_connections <pub_presqos_Connection> (items);
  }

  //
  // dst_of_pub_presqos_Connection
  //
  GAME::Mga::Collection_T <pub_presqos_Connection> PresentationQosPolicy_Impl::dst_of_pub_presqos_Connection (void) const
  {
    return this->in_connections <pub_presqos_Connection> ("dst");
  }
}

