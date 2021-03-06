#include "StdAfx.h"
#include "GetException.h"

#if !defined (__GAME_INLINE__)
#include "GetException.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string GetException_Impl::metaname ("GetException");

  //
  // is_abstract
  //
  const bool GetException_Impl::is_abstract = false;

  //
  // _create (const ReadonlyAttribute_in)
  //
  GetException GetException_Impl::_create (const ReadonlyAttribute_in parent)
  {
    return ::GAME::Mga::create < GetException > (parent, GetException_Impl::metaname);
  }

  //
  // accept
  //
  void GetException_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_GetException (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ReadonlyAttribute
  //
  ReadonlyAttribute GetException_Impl::parent_ReadonlyAttribute (void)
  {
    return ReadonlyAttribute::_narrow (this->parent ());
  }

  //
  // ExceptionType_is_nil
  //
  bool GetException_Impl::ExceptionType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_ExceptionType
  //
  void GetException_Impl::refers_to_ExceptionType (ExceptionType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ExceptionType
  //
  ExceptionType GetException_Impl::refers_to_ExceptionType (void) const
  {
    return ExceptionType::_narrow (this->refers_to ());
  }
}

