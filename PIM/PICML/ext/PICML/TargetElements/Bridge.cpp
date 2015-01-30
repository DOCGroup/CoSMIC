// $Id$

#include "StdAfx.h"
#include "Bridge.h"

#if !defined (__GAME_INLINE__)
#include "Bridge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Resource.h"
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
  const std::string Bridge_Impl::metaname ("Bridge");

  //
  // _create (const Domain_in)
  //
  Bridge Bridge_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create < Bridge > (parent, Bridge_Impl::metaname);
  }

  //
  // accept
  //
  void Bridge_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Bridge (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Domain
  //
  Domain Bridge_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // dst_of_BridgeConnection
  //
  size_t Bridge_Impl::dst_of_BridgeConnection (std::vector <BridgeConnection> & items) const
  {
    return this->in_connections <BridgeConnection> (items);
  }

  //
  // dst_of_BridgeConnection
  //
  GAME::Mga::Collection_T <BridgeConnection> Bridge_Impl::dst_of_BridgeConnection (void) const
  {
    return this->in_connections <BridgeConnection> ("dst");
  }

  //
  // get_Resources
  //
  size_t Bridge_Impl::get_Resources (std::vector <Resource> & items) const
  {
    return this->children (items);
  }

  //
  // get_Resources
  //
  ::GAME::Mga::Collection_T <Resource> Bridge_Impl::get_Resources (void) const
  {
    return this->children <Resource> ();
  }
}

