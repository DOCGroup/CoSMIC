// $Id$

#include "StdAfx.h"
#include "ExceptionRef.h"

#if !defined (__GAME_INLINE__)
#include "ExceptionRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"
#include "PICML/OperationTypes/HasExceptions.h"
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
  // _create (const HasExceptions_in)
  //
  ExceptionRef ExceptionRef_Impl::_create (const HasExceptions_in parent)
  {
    return ::GAME::Mga::create_object < ExceptionRef > (parent, ExceptionRef_Impl::metaname);
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
  // ExceptionType_is_nil
  //
  bool ExceptionRef_Impl::ExceptionType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ExceptionType
  //
  ExceptionType ExceptionRef_Impl::get_ExceptionType (void) const
  {
    return ExceptionType::_narrow (this->refers_to ());
  }
}

