// $Id$

#include "StdAfx.h"
#include "Interconnect.h"

#if !defined (__GAME_INLINE__)
#include "Interconnect.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/Domain/BridgeConnection.h"
#include "PICML/TargetElements/Resource.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Interconnect_Impl::metaname ("Interconnect");

  //
  // _create (const Domain_in)
  //
  Interconnect Interconnect_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < Interconnect > (parent, Interconnect_Impl::metaname);
  }

  //
  // accept
  //
  void Interconnect_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Interconnect (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // src_BridgeConnection
  //
  size_t Interconnect_Impl::src_BridgeConnection (std::vector <BridgeConnection> & items) const
  {
    return this->in_connections <BridgeConnection> (items);
  }

  //
  // dst_InterconnectConnection
  //
  size_t Interconnect_Impl::dst_InterconnectConnection (std::vector <InterconnectConnection> & items) const
  {
    return this->in_connections <InterconnectConnection> (items);
  }

  //
  // get_Resources
  //
  size_t Interconnect_Impl::get_Resources (std::vector <Resource> & items) const
  {
    return this->children (items);
  }

  //
  // get_Resources
  //
  ::GAME::Mga::Iterator <Resource> Interconnect_Impl::get_Resources (void) const
  {
    return this->children <Resource> ();
  }
}

