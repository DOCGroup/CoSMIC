// $Id$

#include "StdAfx.h"
#include "Constant.h"

#if !defined (__GAME_INLINE__)
#include "Constant.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Constant_Impl::metaname ("Constant");

  //
  // _create (const Package_in)
  //
  Constant Constant_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < Constant > (parent, Constant_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Constant Constant_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Constant > (parent, Constant_Impl::metaname);
  }

  //
  // _create (const HasOperations_in)
  //
  Constant Constant_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < Constant > (parent, Constant_Impl::metaname);
  }

  //
  // accept
  //
  void Constant_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Constant (this);
    else
      v->visit_Reference (this);
  }

  //
  // ConstantType_is_nil
  //
  bool Constant_Impl::ConstantType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ConstantType
  //
  ConstantType Constant_Impl::get_ConstantType (void) const
  {
    return ConstantType::_narrow (this->refers_to ());
  }
}

