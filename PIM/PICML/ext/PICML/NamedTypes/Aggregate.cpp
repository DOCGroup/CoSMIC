// $Id$

#include "StdAfx.h"
#include "Aggregate.h"

#if !defined (__GAME_INLINE__)
#include "Aggregate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Key.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
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
  // is_abstract
  //
  const bool Aggregate_Impl::is_abstract (0);

  //
  // _create (const ConnectorObject_in)
  //
  Aggregate Aggregate_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create < Aggregate > (parent, Aggregate_Impl::metaname);
  }

  //
  // _create (const HasOperations_in)
  //
  Aggregate Aggregate_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create < Aggregate > (parent, Aggregate_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  Aggregate Aggregate_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < Aggregate > (parent, Aggregate_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Aggregate Aggregate_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < Aggregate > (parent, Aggregate_Impl::metaname);
  }

  //
  // accept
  //
  void Aggregate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Aggregate (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ConnectorObject
  //
  ConnectorObject Aggregate_Impl::parent_ConnectorObject (void)
  {
    return ConnectorObject::_narrow (this->parent ());
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
    return this->children <Key> ().first ();
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
  ::GAME::Mga::Collection_T <Member> Aggregate_Impl::get_Members (void) const
  {
    return this->children <Member> ();
  }

  //
  // get_ArrayMembers
  //
  size_t Aggregate_Impl::get_ArrayMembers (std::vector <ArrayMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArrayMembers
  //
  ::GAME::Mga::Collection_T <ArrayMember> Aggregate_Impl::get_ArrayMembers (void) const
  {
    return this->children <ArrayMember> ();
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
  ::GAME::Mga::Collection_T <KeyMember> Aggregate_Impl::get_KeyMembers (void) const
  {
    return this->children <KeyMember> ();
  }
}

