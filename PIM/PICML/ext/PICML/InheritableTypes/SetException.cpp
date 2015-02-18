// $Id$

#include "StdAfx.h"
#include "SetException.h"

#if !defined (__GAME_INLINE__)
#include "SetException.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SetException_Impl::metaname ("SetException");

  //
  // is_abstract
  //
  const bool SetException_Impl::is_abstract = false;

  //
  // _create (const Attribute_in)
  //
  SetException SetException_Impl::_create (const Attribute_in parent)
  {
    return ::GAME::Mga::create < SetException > (parent, SetException_Impl::metaname);
  }

  //
  // accept
  //
  void SetException_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SetException (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Attribute
  //
  Attribute SetException_Impl::parent_Attribute (void)
  {
    return Attribute::_narrow (this->parent ());
  }

  //
  // ExceptionType_is_nil
  //
  bool SetException_Impl::ExceptionType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ExceptionType
  //
  void SetException_Impl::refers_to_ExceptionType (ExceptionType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ExceptionType
  //
  ExceptionType SetException_Impl::refers_to_ExceptionType (void) const
  {
    return ExceptionType::_narrow (this->refers_to ());
  }
}

