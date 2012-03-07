// $Id$

#include "StdAfx.h"
#include "Key.h"

#if !defined (__GAME_INLINE__)
#include "Key.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/KeyMember.h"
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
  // _create (const Aggregate_in)
  //
  Key Key_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create_object < Key > (parent, Key_Impl::metaname);
  }

  //
  // accept
  //
  void Key_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Key (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // src_KeyMember
  //
  size_t Key_Impl::src_KeyMember (std::vector <KeyMember> & items) const
  {
    return this->in_connections <KeyMember> (items);
  }
}

