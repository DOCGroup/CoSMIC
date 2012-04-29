// $Id$

#include "StdAfx.h"
#include "InterconnectConnection.h"

#if !defined (__GAME_INLINE__)
#include "InterconnectConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Node.h"
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
  // _create (const Domain_in)
  //
  InterconnectConnection InterconnectConnection_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < InterconnectConnection > (parent, InterconnectConnection_Impl::metaname);
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

