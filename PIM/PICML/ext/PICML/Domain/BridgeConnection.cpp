// $Id$

#include "StdAfx.h"
#include "BridgeConnection.h"

#if !defined (__GAME_INLINE__)
#include "BridgeConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/Domain/Domain.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string BridgeConnection_Impl::metaname ("BridgeConnection");

  //
  // is_abstract
  //
  const bool BridgeConnection_Impl::is_abstract (0);

  //
  // _create (const Domain_in, Interconnect_in src, Bridge_in dst)
  //
  BridgeConnection BridgeConnection_Impl::_create (const Domain_in parent, Interconnect_in src, Bridge_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, BridgeConnection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void BridgeConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_BridgeConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Domain
  //
  Domain BridgeConnection_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // Interconnect
  //
  Interconnect BridgeConnection_Impl::src_Interconnect (void) const
  {
    return Interconnect::_narrow (this->src ());
  }

  //
  // Bridge
  //
  Bridge BridgeConnection_Impl::dst_Bridge (void) const
  {
    return Bridge::_narrow (this->dst ());
  }
}

