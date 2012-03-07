// $Id$

#include "StdAfx.h"
#include "Alias.h"

#if !defined (__GAME_INLINE__)
#include "Alias.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Alias_Impl::metaname ("Alias");

  //
  // _create (const HasOperations_in)
  //
  Alias Alias_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < Alias > (parent, Alias_Impl::metaname);
  }

  //
  // accept
  //
  void Alias_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Alias (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // MemberType_is_nil
  //
  bool Alias_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType Alias_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

