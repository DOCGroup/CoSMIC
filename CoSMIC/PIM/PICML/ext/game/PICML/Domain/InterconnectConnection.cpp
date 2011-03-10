// $Id$

#include "stdafx.h"
#include "InterconnectConnection.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/Interconnect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InterconnectConnection_Impl::metaname = "InterconnectConnection";

  //
  // InterconnectConnection_Impl
  //
  InterconnectConnection_Impl::InterconnectConnection_Impl (void)
  {
  }

  //
  // InterconnectConnection_Impl
  //
  InterconnectConnection_Impl::InterconnectConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InterconnectConnection_Impl
  //
  InterconnectConnection_Impl::~InterconnectConnection_Impl (void)
  {
  }

  //
  // accept
  //
  void InterconnectConnection_Impl::accept (Visitor * v)
  {
    v->visit_InterconnectConnection (this);
  }

  //
  // _create
  //
  InterconnectConnection InterconnectConnection_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object <InterconnectConnection> (parent, InterconnectConnection_Impl::metaname);
  }

  //
  // src_Node
  //
  Node InterconnectConnection_Impl::src_Node (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Node::_narrow (target);
  }

  //
  // dst_Interconnect
  //
  Interconnect InterconnectConnection_Impl::dst_Interconnect (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Interconnect::_narrow (target);
  }

  //
  // parent_Domain
  //
  Domain InterconnectConnection_Impl::parent_Domain (void) const
  {
    return ::GAME::Mga::get_parent <Domain> (this->object_.p);
  }
}

