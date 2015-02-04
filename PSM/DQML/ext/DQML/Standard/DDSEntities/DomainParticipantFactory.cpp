// $Id$

#include "StdAfx.h"
#include "DomainParticipantFactory.h"

#if !defined (__GAME_INLINE__)
#include "DomainParticipantFactory.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/EntityFactoryQosPolicy/dpfactory_entityfactory_Connection.h"
#include "DQML/Standard/Main/dpf_dp_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DomainParticipantFactory_Impl::metaname ("DomainParticipantFactory");

  //
  // is_abstract
  //
  const bool DomainParticipantFactory_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in)
  //
  DomainParticipantFactory DomainParticipantFactory_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < DomainParticipantFactory > (parent, DomainParticipantFactory_Impl::metaname);
  }

  //
  // accept
  //
  void DomainParticipantFactory_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DomainParticipantFactory (this);
    else
      v->visit_Model (this);
  }

  //
  // src_of_dpfactory_entityfactory_Connection
  //
  size_t DomainParticipantFactory_Impl::src_of_dpfactory_entityfactory_Connection (std::vector <dpfactory_entityfactory_Connection> & items) const
  {
    return this->in_connections <dpfactory_entityfactory_Connection> (items);
  }

  //
  // src_of_dpfactory_entityfactory_Connection
  //
  GAME::Mga::Collection_T <dpfactory_entityfactory_Connection> DomainParticipantFactory_Impl::src_of_dpfactory_entityfactory_Connection (void) const
  {
    return this->in_connections <dpfactory_entityfactory_Connection> ("src");
  }

  //
  // src_of_dpf_dp_Connection
  //
  size_t DomainParticipantFactory_Impl::src_of_dpf_dp_Connection (std::vector <dpf_dp_Connection> & items) const
  {
    return this->in_connections <dpf_dp_Connection> (items);
  }

  //
  // src_of_dpf_dp_Connection
  //
  GAME::Mga::Collection_T <dpf_dp_Connection> DomainParticipantFactory_Impl::src_of_dpf_dp_Connection (void) const
  {
    return this->in_connections <dpf_dp_Connection> ("src");
  }
}

