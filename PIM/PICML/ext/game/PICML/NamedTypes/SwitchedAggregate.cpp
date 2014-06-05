// $Id$

#include "StdAfx.h"
#include "SwitchedAggregate.h"

#if !defined (__GAME_INLINE__)
#include "SwitchedAggregate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/NamedTypes/Label.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "PICML/NamedTypes/Discriminator.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SwitchedAggregate_Impl::metaname ("SwitchedAggregate");

  //
  // _create (const HasOperations_in)
  //
  SwitchedAggregate SwitchedAggregate_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < SwitchedAggregate > (parent, SwitchedAggregate_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  SwitchedAggregate SwitchedAggregate_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < SwitchedAggregate > (parent, SwitchedAggregate_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  SwitchedAggregate SwitchedAggregate_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < SwitchedAggregate > (parent, SwitchedAggregate_Impl::metaname);
  }

  //
  // accept
  //
  void SwitchedAggregate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SwitchedAggregate (this);
    else
      v->visit_Model (this);
  }

  //
  // has_Discriminator
  //
  bool SwitchedAggregate_Impl::has_Discriminator (void) const
  {
    return this->children <Discriminator> ().count () == 1;
  }

  //
  // get_Discriminator
  //
  Discriminator SwitchedAggregate_Impl::get_Discriminator (void) const
  {
    return this->children <Discriminator> ().first ();
  }

  //
  // get_Members
  //
  size_t SwitchedAggregate_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_Members
  //
  ::GAME::Mga::Collection_T <Member> SwitchedAggregate_Impl::get_Members (void) const
  {
    return this->children <Member> ();
  }

  //
  // get_ArrayMembers
  //
  size_t SwitchedAggregate_Impl::get_ArrayMembers (std::vector <ArrayMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArrayMembers
  //
  ::GAME::Mga::Collection_T <ArrayMember> SwitchedAggregate_Impl::get_ArrayMembers (void) const
  {
    return this->children <ArrayMember> ();
  }

  //
  // get_Labels
  //
  size_t SwitchedAggregate_Impl::get_Labels (std::vector <Label> & items) const
  {
    return this->children (items);
  }

  //
  // get_Labels
  //
  ::GAME::Mga::Collection_T <Label> SwitchedAggregate_Impl::get_Labels (void) const
  {
    return this->children <Label> ();
  }

  //
  // get_LabelConnections
  //
  size_t SwitchedAggregate_Impl::get_LabelConnections (std::vector <LabelConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_LabelConnections
  //
  ::GAME::Mga::Collection_T <LabelConnection> SwitchedAggregate_Impl::get_LabelConnections (void) const
  {
    return this->children <LabelConnection> ();
  }
}

