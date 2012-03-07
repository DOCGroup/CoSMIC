// $Id$

#include "StdAfx.h"
#include "Member.h"

#if !defined (__GAME_INLINE__)
#include "Member.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Member_Impl::metaname ("Member");

  //
  // _create (const Exception_in)
  //
  Member Member_Impl::_create (const Exception_in parent)
  {
    return ::GAME::Mga::create_object < Member > (parent, Member_Impl::metaname);
  }

  //
  // _create (const Aggregate_in)
  //
  Member Member_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create_object < Member > (parent, Member_Impl::metaname);
  }

  //
  // _create (const SwitchedAggregate_in)
  //
  Member Member_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object < Member > (parent, Member_Impl::metaname);
  }

  //
  // _create (const ObjectByValue_in)
  //
  Member Member_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create_object < Member > (parent, Member_Impl::metaname);
  }

  //
  // accept
  //
  void Member_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Member (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // src_LabelConnection
  //
  size_t Member_Impl::src_LabelConnection (std::vector <LabelConnection> & items) const
  {
    return this->in_connections <LabelConnection> (items);
  }

  //
  // src_MakeMemberPrivate
  //
  size_t Member_Impl::src_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const
  {
    return this->in_connections <MakeMemberPrivate> (items);
  }

  //
  // dst_KeyMember
  //
  size_t Member_Impl::dst_KeyMember (std::vector <KeyMember> & items) const
  {
    return this->in_connections <KeyMember> (items);
  }

  //
  // MemberType_is_nil
  //
  bool Member_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType Member_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

