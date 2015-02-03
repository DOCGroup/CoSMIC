// $Id$

#include "StdAfx.h"
#include "MakeMemberPrivate.h"

#if !defined (__GAME_INLINE__)
#include "MakeMemberPrivate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/PrivateFlag.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MakeMemberPrivate_Impl::metaname ("MakeMemberPrivate");

  //
  // is_abstract
  //
  const bool MakeMemberPrivate_Impl::is_abstract (0);

  //
  // _create (const ObjectByValue_in, Member_in src, PrivateFlag_in dst)
  //
  MakeMemberPrivate MakeMemberPrivate_Impl::_create (const ObjectByValue_in parent, Member_in src, PrivateFlag_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, MakeMemberPrivate_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void MakeMemberPrivate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MakeMemberPrivate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ObjectByValue
  //
  ObjectByValue MakeMemberPrivate_Impl::parent_ObjectByValue (void)
  {
    return ObjectByValue::_narrow (this->parent ());
  }

  //
  // Member
  //
  Member MakeMemberPrivate_Impl::src_Member (void) const
  {
    return Member::_narrow (this->src ());
  }

  //
  // PrivateFlag
  //
  PrivateFlag MakeMemberPrivate_Impl::dst_PrivateFlag (void) const
  {
    return PrivateFlag::_narrow (this->dst ());
  }
}

