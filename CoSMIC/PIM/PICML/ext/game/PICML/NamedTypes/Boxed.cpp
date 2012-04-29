// $Id$

#include "StdAfx.h"
#include "Boxed.h"

#if !defined (__GAME_INLINE__)
#include "Boxed.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/NamedTypes/MemberType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Boxed_Impl::metaname ("Boxed");

  //
  // _create (const Package_in)
  //
  Boxed Boxed_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < Boxed > (parent, Boxed_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Boxed Boxed_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Boxed > (parent, Boxed_Impl::metaname);
  }

  //
  // accept
  //
  void Boxed_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Boxed (this);
    else
      v->visit_Reference (this);
  }

  //
  // MemberType_is_nil
  //
  bool Boxed_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType Boxed_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

