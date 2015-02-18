// $Id$

#include "StdAfx.h"
#include "Key.h"

#if !defined (__GAME_INLINE__)
#include "Key.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Key_Impl::metaname ("Key");

  //
  // is_abstract
  //
  const bool Key_Impl::is_abstract = false;

  //
  // _create (const Aggregate_in)
  //
  Key Key_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create < Key > (parent, Key_Impl::metaname);
  }

  //
  // accept
  //
  void Key_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Key (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_Aggregate
  //
  Aggregate Key_Impl::parent_Aggregate (void)
  {
    return Aggregate::_narrow (this->parent ());
  }

  //
  // src_of_KeyMember
  //
  size_t Key_Impl::src_of_KeyMember (std::vector <KeyMember> & items) const
  {
    return this->in_connections <KeyMember> (items);
  }

  //
  // has_src_of_KeyMember
  //
  bool Key_Impl::has_src_of_KeyMember (void) const
  {
    return this->in_connections <KeyMember> ("src").count () == 1;
  }

  //
  // src_of_KeyMember
  //
  KeyMember Key_Impl::src_of_KeyMember (void) const
  {
    return this->in_connections <KeyMember> ("src").first ();
  }
}

