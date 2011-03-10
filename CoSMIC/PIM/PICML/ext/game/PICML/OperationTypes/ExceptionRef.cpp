// $Id$

#include "stdafx.h"
#include "ExceptionRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExceptionRef_Impl::metaname = "ExceptionRef";

  //
  // ExceptionRef_Impl
  //
  ExceptionRef_Impl::ExceptionRef_Impl (void)
  {
  }

  //
  // ExceptionRef_Impl
  //
  ExceptionRef_Impl::ExceptionRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExceptionRef_Impl
  //
  ExceptionRef_Impl::~ExceptionRef_Impl (void)
  {
  }

  //
  // accept
  //
  void ExceptionRef_Impl::accept (Visitor * v)
  {
    v->visit_ExceptionRef (this);
  }

  //
  // _create
  //
  ExceptionRef ExceptionRef_Impl::_create (const HasExceptions_in parent)
  {
    return ::GAME::Mga::create_object <ExceptionRef> (parent, ExceptionRef_Impl::metaname);
  }

  //
  // parent_HasExceptions
  //
  HasExceptions ExceptionRef_Impl::parent_HasExceptions (void) const
  {
    return ::GAME::Mga::get_parent <HasExceptions> (this->object_.p);
  }
}

