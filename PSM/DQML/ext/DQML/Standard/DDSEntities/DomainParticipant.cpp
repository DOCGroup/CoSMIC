// $Id$

#include "StdAfx.h"
#include "DomainParticipant.h"

#if !defined (__GAME_INLINE__)
#include "DomainParticipant.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/dp_sub_Connection.h"
#include "DQML/Standard/UserDataQosPolicy/dp_userdata_Connection.h"
#include "DQML/Standard/Main/dpf_dp_Connection.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dp_entityfactory_Connection.h"
#include "DQML/Standard/Main/dp_pub_Connection.h"
#include "DQML/Standard/Main/dp_topic_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DomainParticipant_Impl::metaname ("DomainParticipant");

  //
  // is_abstract
  //
  const bool DomainParticipant_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in)
  //
  DomainParticipant DomainParticipant_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DomainParticipant > (parent, DomainParticipant_Impl::metaname);
  }

  //
  // accept
  //
  void DomainParticipant_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DomainParticipant (this);
    else
      v->visit_Model (this);
  }

  //
  // src_of_dp_sub_Connection
  //
  size_t DomainParticipant_Impl::src_of_dp_sub_Connection (std::vector <dp_sub_Connection> & items) const
  {
    return this->in_connections <dp_sub_Connection> (items);
  }

  //
  // src_of_dp_sub_Connection
  //
  GAME::Mga::Collection_T <dp_sub_Connection> DomainParticipant_Impl::src_of_dp_sub_Connection (void) const
  {
    return this->in_connections <dp_sub_Connection> ("src");
  }

  //
  // src_of_dp_userdata_Connection
  //
  size_t DomainParticipant_Impl::src_of_dp_userdata_Connection (std::vector <dp_userdata_Connection> & items) const
  {
    return this->in_connections <dp_userdata_Connection> (items);
  }

  //
  // has_src_of_dp_userdata_Connection
  //
  bool DomainParticipant_Impl::has_src_of_dp_userdata_Connection (void) const
  {
    return this->in_connections <dp_userdata_Connection> ("src").count () == 1;
  }

  //
  // src_of_dp_userdata_Connection
  //
  dp_userdata_Connection DomainParticipant_Impl::src_of_dp_userdata_Connection (void) const
  {
    return this->in_connections <dp_userdata_Connection> ("src").first ();
  }

  //
  // src_of_dp_entityfactory_Connection
  //
  size_t DomainParticipant_Impl::src_of_dp_entityfactory_Connection (std::vector <dp_entityfactory_Connection> & items) const
  {
    return this->in_connections <dp_entityfactory_Connection> (items);
  }

  //
  // has_src_of_dp_entityfactory_Connection
  //
  bool DomainParticipant_Impl::has_src_of_dp_entityfactory_Connection (void) const
  {
    return this->in_connections <dp_entityfactory_Connection> ("src").count () == 1;
  }

  //
  // src_of_dp_entityfactory_Connection
  //
  dp_entityfactory_Connection DomainParticipant_Impl::src_of_dp_entityfactory_Connection (void) const
  {
    return this->in_connections <dp_entityfactory_Connection> ("src").first ();
  }

  //
  // src_of_dp_pub_Connection
  //
  size_t DomainParticipant_Impl::src_of_dp_pub_Connection (std::vector <dp_pub_Connection> & items) const
  {
    return this->in_connections <dp_pub_Connection> (items);
  }

  //
  // src_of_dp_pub_Connection
  //
  GAME::Mga::Collection_T <dp_pub_Connection> DomainParticipant_Impl::src_of_dp_pub_Connection (void) const
  {
    return this->in_connections <dp_pub_Connection> ("src");
  }

  //
  // src_of_dp_topic_Connection
  //
  size_t DomainParticipant_Impl::src_of_dp_topic_Connection (std::vector <dp_topic_Connection> & items) const
  {
    return this->in_connections <dp_topic_Connection> (items);
  }

  //
  // src_of_dp_topic_Connection
  //
  GAME::Mga::Collection_T <dp_topic_Connection> DomainParticipant_Impl::src_of_dp_topic_Connection (void) const
  {
    return this->in_connections <dp_topic_Connection> ("src");
  }

  //
  // dst_of_dpf_dp_Connection
  //
  size_t DomainParticipant_Impl::dst_of_dpf_dp_Connection (std::vector <dpf_dp_Connection> & items) const
  {
    return this->in_connections <dpf_dp_Connection> (items);
  }

  //
  // dst_of_dpf_dp_Connection
  //
  dpf_dp_Connection DomainParticipant_Impl::dst_of_dpf_dp_Connection (void) const
  {
    return this->in_connections <dpf_dp_Connection> ("dst").first ();
  }
}

