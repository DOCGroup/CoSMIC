// $Id$

#include "stdafx.h"
#include "Member.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Member_Impl::metaname = "Member";

  //
  // Member_Impl
  //
  Member_Impl::Member_Impl (void)
  {
  }

  //
  // Member_Impl
  //
  Member_Impl::Member_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Member_Impl
  //
  Member_Impl::~Member_Impl (void)
  {
  }

  //
  // accept
  //
  void Member_Impl::accept (Visitor * v)
  {
    v->visit_Member (this);
  }

  //
  // _create
  //
  Member Member_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create_object <Member> (parent, Member_Impl::metaname);
  }

  //
  // _create
  //
  Member Member_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object <Member> (parent, Member_Impl::metaname);
  }

  //
  // in_LabelConnection_connections
  //
  size_t Member_Impl::in_LabelConnection_connections (std::vector <LabelConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_KeyMember_connections
  //
  size_t Member_Impl::in_KeyMember_connections (std::vector <KeyMember> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Aggregate
  //
  Aggregate Member_Impl::parent_Aggregate (void) const
  {
    return ::GAME::Mga::get_parent <Aggregate> (this->object_.p);
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate Member_Impl::parent_SwitchedAggregate (void) const
  {
    return ::GAME::Mga::get_parent <SwitchedAggregate> (this->object_.p);
  }

  //
  // refers_to_MemberType
  //
  MemberType Member_Impl::refers_to_MemberType (void) const
  {
    return ::GAME::Mga::get_refers_to <MemberType> (this);
  }
}

