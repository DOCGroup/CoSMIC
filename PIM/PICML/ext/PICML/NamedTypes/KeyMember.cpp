#include "StdAfx.h"
#include "KeyMember.h"

#if !defined (__GAME_INLINE__)
#include "KeyMember.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/NamedTypes/Key.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string KeyMember_Impl::metaname ("KeyMember");

  //
  // is_abstract
  //
  const bool KeyMember_Impl::is_abstract = false;

  //
  // _create (const Aggregate_in, Key_in src, Member_in dst)
  //
  KeyMember KeyMember_Impl::_create (const Aggregate_in parent, Key_in src, Member_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, KeyMember_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void KeyMember_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_KeyMember (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Aggregate
  //
  Aggregate KeyMember_Impl::parent_Aggregate (void)
  {
    return Aggregate::_narrow (this->parent ());
  }

  //
  // Key
  //
  Key KeyMember_Impl::src_Key (void) const
  {
    return Key::_narrow (this->src ());
  }

  //
  // Member
  //
  Member KeyMember_Impl::dst_Member (void) const
  {
    return Member::_narrow (this->dst ());
  }
}

