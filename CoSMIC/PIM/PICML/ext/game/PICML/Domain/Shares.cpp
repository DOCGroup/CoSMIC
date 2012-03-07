// $Id$

#include "StdAfx.h"
#include "Shares.h"

#if !defined (__GAME_INLINE__)
#include "Shares.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/SharedResource.h"
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
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Shares (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

