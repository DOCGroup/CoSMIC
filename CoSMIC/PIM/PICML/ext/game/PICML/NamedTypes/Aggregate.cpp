// $Id$

#include "StdAfx.h"
#include "Aggregate.h"

#if !defined (__GAME_INLINE__)
#include "Aggregate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/NamedTypes/Key.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Aggregate_Impl::metaname ("Aggregate");

  //
  // _create (const ConnectorObject_in)
  //
  Aggregate Aggregate_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < Aggregate > (parent, Aggregate_Impl::metaname);
  }

  //
  // _create (const HasOperations_in)
  //
  Aggregate Aggregate_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < Aggregate > (parent, Aggregate_Impl::metaname);
  }

  //
  // accept
  //
  void Aggregate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Aggregate (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // has_Key
  //
  bool Aggregate_Impl::has_Key (void) const
  {
    return this->children <Key> ().count () == 1;
  }

  //
  // get_Key
  //
  Key Aggregate_Impl::get_Key (void) const
  {
    return this->children <Key> ().item ();
  }

  //
  // get_Members
  //
  size_t Aggregate_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_Members
  //
  ::GAME::Mga::Iterator <Member> Aggregate_Impl::get_Members (void) const
  {
    return this->children <Member> ();
  }

  //
  // get_KeyMembers
  //
  size_t Aggregate_Impl::get_KeyMembers (std::vector <KeyMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_KeyMembers
  //
  ::GAME::Mga::Iterator <KeyMember> Aggregate_Impl::get_KeyMembers (void) const
  {
    return this->children <KeyMember> ();
  }
}

