// $Id$

#include "StdAfx.h"
#include "Interconnect.h"

#if !defined (__GAME_INLINE__)
#include "Interconnect.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Resource.h"
#include "PICML/Domain/InterconnectConnection.h"
#include "PICML/Domain/BridgeConnection.h"
#include "PICML/Domain/Domain.h"
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
  // is_abstract
  //
  const bool Interconnect_Impl::is_abstract (0);

  //
  // _create (const Domain_in)
  //
  Interconnect Interconnect_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create < Interconnect > (parent, Interconnect_Impl::metaname);
  }

  //
  // accept
  //
  void Interconnect_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Interconnect (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Domain
  //
  Domain Interconnect_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // src_of_BridgeConnection
  //
  size_t Interconnect_Impl::src_of_BridgeConnection (std::vector <BridgeConnection> & items) const
  {
    return this->in_connections <BridgeConnection> (items);
  }

  //
  // src_of_BridgeConnection
  //
  GAME::Mga::Collection_T <BridgeConnection> Interconnect_Impl::src_of_BridgeConnection (void) const
  {
    return this->in_connections <BridgeConnection> ("src");
  }

  //
  // dst_of_InterconnectConnection
  //
  size_t Interconnect_Impl::dst_of_InterconnectConnection (std::vector <InterconnectConnection> & items) const
  {
    return this->in_connections <InterconnectConnection> (items);
  }

  //
  // dst_of_InterconnectConnection
  //
  GAME::Mga::Collection_T <InterconnectConnection> Interconnect_Impl::dst_of_InterconnectConnection (void) const
  {
    return this->in_connections <InterconnectConnection> ("dst");
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
  ::GAME::Mga::Collection_T <Resource> Interconnect_Impl::get_Resources (void) const
  {
    return this->children <Resource> ();
  }
}

