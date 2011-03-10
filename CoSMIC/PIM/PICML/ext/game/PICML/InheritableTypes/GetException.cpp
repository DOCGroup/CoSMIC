// $Id$

#include "stdafx.h"
#include "GetException.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GetException_Impl::metaname = "GetException";

  //
  // GetException_Impl
  //
  GetException_Impl::GetException_Impl (void)
  {
  }

  //
  // GetException_Impl
  //
  GetException_Impl::GetException_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GetException_Impl
  //
  GetException_Impl::~GetException_Impl (void)
  {
  }

  //
  // accept
  //
  void GetException_Impl::accept (Visitor * v)
  {
    v->visit_GetException (this);
  }

  //
  // _create
  //
  GetException GetException_Impl::_create (const ReadonlyAttribute_in parent)
  {
    return ::GAME::Mga::create_object <GetException> (parent, GetException_Impl::metaname);
  }

  //
  // parent_ReadonlyAttribute
  //
  ReadonlyAttribute GetException_Impl::parent_ReadonlyAttribute (void) const
  {
    return ::GAME::Mga::get_parent <ReadonlyAttribute> (this->object_.p);
  }
}

