// $Id$

#include "stdafx.h"
#include "KeyMember.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Key.h"
#include "PICML/NamedTypes/Member.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string KeyMember_Impl::metaname = "KeyMember";

  //
  // KeyMember_Impl
  //
  KeyMember_Impl::KeyMember_Impl (void)
  {
  }

  //
  // KeyMember_Impl
  //
  KeyMember_Impl::KeyMember_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~KeyMember_Impl
  //
  KeyMember_Impl::~KeyMember_Impl (void)
  {
  }

  //
  // accept
  //
  void KeyMember_Impl::accept (Visitor * v)
  {
    v->visit_KeyMember (this);
  }

  //
  // _create
  //
  KeyMember KeyMember_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create_object <KeyMember> (parent, KeyMember_Impl::metaname);
  }

  //
  // src_Key
  //
  Key KeyMember_Impl::src_Key (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Key::_narrow (target);
  }

  //
  // dst_Member
  //
  Member KeyMember_Impl::dst_Member (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Member::_narrow (target);
  }

  //
  // parent_Aggregate
  //
  Aggregate KeyMember_Impl::parent_Aggregate (void) const
  {
    return ::GAME::Mga::get_parent <Aggregate> (this->object_.p);
  }
}

