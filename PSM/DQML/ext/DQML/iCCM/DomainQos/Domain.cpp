// $Id$

#include "StdAfx.h"
#include "Domain.h"

#if !defined (__GAME_INLINE__)
#include "Domain.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainQos/PublishesConnection.h"
#include "DQML/iCCM/DomainParticipantQos/Participant.h"
#include "DQML/iCCM/DomainQos/DomainQosFolder.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string Domain_Impl::metaname ("Domain");

  //
  // _create (const DomainQosFolder_in)
  //
  Domain Domain_Impl::_create (const DomainQosFolder_in parent)
  {
    return ::GAME::Mga::create_root_object < Domain > (parent, Domain_Impl::metaname);
  }

  //
  // accept
  //
  void Domain_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Domain (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_DomainQosFolder
  //
  DomainQosFolder Domain_Impl::parent_DomainQosFolder (void)
  {
    return DomainQosFolder::_narrow (this->parent ());
  }

  //
  // get_PublishesConnections
  //
  size_t Domain_Impl::get_PublishesConnections (std::vector <PublishesConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_PublishesConnections
  //
  ::GAME::Mga::Collection_T <PublishesConnection> Domain_Impl::get_PublishesConnections (void) const
  {
    return this->children <PublishesConnection> ();
  }

  //
  // get_Participants
  //
  size_t Domain_Impl::get_Participants (std::vector <Participant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Participants
  //
  ::GAME::Mga::Collection_T <Participant> Domain_Impl::get_Participants (void) const
  {
    return this->children <Participant> ();
  }
}

