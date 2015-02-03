// $Id$

#include "StdAfx.h"
#include "ExceptionRef.h"

#if !defined (__GAME_INLINE__)
#include "ExceptionRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/OperationTypes/LookupOperation.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExceptionRef_Impl::metaname ("ExceptionRef");

  //
  // is_abstract
  //
  const bool ExceptionRef_Impl::is_abstract (0);

  //
  // _create (const HasExceptions_in)
  //
  ExceptionRef ExceptionRef_Impl::_create (const HasExceptions_in parent)
  {
    return ::GAME::Mga::create < ExceptionRef > (parent, ExceptionRef_Impl::metaname);
  }

  //
  // accept
  //
  void ExceptionRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExceptionRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_HasExceptions
  //
  HasExceptions ExceptionRef_Impl::parent_HasExceptions (void)
  {
    return HasExceptions::_narrow (this->parent ());
  }

  //
  // ExceptionType_is_nil
  //
  bool ExceptionRef_Impl::ExceptionType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ExceptionType
  //
  void ExceptionRef_Impl::refers_to_ExceptionType (ExceptionType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ExceptionType
  //
  ExceptionType ExceptionRef_Impl::refers_to_ExceptionType (void) const
  {
    return ExceptionType::_narrow (this->refers_to ());
  }
}

