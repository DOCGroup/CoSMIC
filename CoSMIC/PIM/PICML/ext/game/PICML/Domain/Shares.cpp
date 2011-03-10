// $Id$

#include "stdafx.h"
#include "Shares.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/SharedResource.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Shares_Impl::metaname = "Shares";

  //
  // Shares_Impl
  //
  Shares_Impl::Shares_Impl (void)
  {
  }

  //
  // Shares_Impl
  //
  Shares_Impl::Shares_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Shares_Impl
  //
  Shares_Impl::~Shares_Impl (void)
  {
  }

  //
  // accept
  //
  void Shares_Impl::accept (Visitor * v)
  {
    v->visit_Shares (this);
  }

  //
  // _create
  //
  Shares Shares_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object <Shares> (parent, Shares_Impl::metaname);
  }

  //
  // src_Node
  //
  Node Shares_Impl::src_Node (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Node::_narrow (target);
  }

  //
  // dst_SharedResource
  //
  SharedResource Shares_Impl::dst_SharedResource (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return SharedResource::_narrow (target);
  }

  //
  // parent_Domain
  //
  Domain Shares_Impl::parent_Domain (void) const
  {
    return ::GAME::Mga::get_parent <Domain> (this->object_.p);
  }
}

