// $Id$

#include "StdAfx.h"
#include "Enum.h"

#if !defined (__GAME_INLINE__)
#include "Enum.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/EnumValue.h"
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
  const std::string Enum_Impl::metaname ("Enum");

  //
  // _create (const HasOperations_in)
  //
  Enum Enum_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < Enum > (parent, Enum_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  Enum Enum_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < Enum > (parent, Enum_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Enum Enum_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Enum > (parent, Enum_Impl::metaname);
  }

  //
  // accept
  //
  void Enum_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Enum (this);
    else
      v->visit_Model (this);
  }

  //
  // get_EnumValues
  //
  size_t Enum_Impl::get_EnumValues (std::vector <EnumValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_EnumValues
  //
  ::GAME::Mga::Collection_T <EnumValue> Enum_Impl::get_EnumValues (void) const
  {
    return this->children <EnumValue> ();
  }
}

