// $Id$

#include "StdAfx.h"
#include "Shares.h"

#if !defined (__GAME_INLINE__)
#include "Shares.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/SharedResource.h"
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
  const std::string Shares_Impl::metaname ("Shares");

  //
  // _create (const Domain_in)
  //
  Shares Shares_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < Shares > (parent, Shares_Impl::metaname);
  }

  //
  // accept
  //
  void Shares_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Shares (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Domain
  //
  Domain Shares_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // Node
  //
  Node Shares_Impl::src_Node (void) const
  {
    return Node::_narrow (this->src ());
  }

  //
  // SharedResource
  //
  SharedResource Shares_Impl::dst_SharedResource (void) const
  {
    return SharedResource::_narrow (this->dst ());
  }
}

