// $Id$

#include "stdafx.h"
#include "BridgeConnection.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Bridge.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BridgeConnection_Impl::metaname = "BridgeConnection";

  //
  // BridgeConnection_Impl
  //
  BridgeConnection_Impl::BridgeConnection_Impl (void)
  {
  }

  //
  // BridgeConnection_Impl
  //
  BridgeConnection_Impl::BridgeConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BridgeConnection_Impl
  //
  BridgeConnection_Impl::~BridgeConnection_Impl (void)
  {
  }

  //
  // accept
  //
  void BridgeConnection_Impl::accept (Visitor * v)
  {
    v->visit_BridgeConnection (this);
  }

  //
  // _create
  //
  BridgeConnection BridgeConnection_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object <BridgeConnection> (parent, BridgeConnection_Impl::metaname);
  }

  //
  // src_Interconnect
  //
  Interconnect BridgeConnection_Impl::src_Interconnect (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Interconnect::_narrow (target);
  }

  //
  // dst_Bridge
  //
  Bridge BridgeConnection_Impl::dst_Bridge (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Bridge::_narrow (target);
  }

  //
  // parent_Domain
  //
  Domain BridgeConnection_Impl::parent_Domain (void) const
  {
    return ::GAME::Mga::get_parent <Domain> (this->object_.p);
  }
}

