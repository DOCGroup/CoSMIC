// $Id$

#include "StdAfx.h"
#include "InterconnectConnection.h"

#if !defined (__GAME_INLINE__)
#include "InterconnectConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/Domain/Domain.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InterconnectConnection_Impl::metaname ("InterconnectConnection");

  //
  // _create (const Domain_in, Node_in src, Interconnect_in dst)
  //
  InterconnectConnection InterconnectConnection_Impl::_create (const Domain_in parent, Node_in src, Interconnect_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, InterconnectConnection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void InterconnectConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InterconnectConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Domain
  //
  Domain InterconnectConnection_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // Node
  //
  Node InterconnectConnection_Impl::src_Node (void) const
  {
    return Node::_narrow (this->src ());
  }

  //
  // Interconnect
  //
  Interconnect InterconnectConnection_Impl::dst_Interconnect (void) const
  {
    return Interconnect::_narrow (this->dst ());
  }
}

