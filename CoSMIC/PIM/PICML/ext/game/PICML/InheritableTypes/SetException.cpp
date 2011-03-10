// $Id$

#include "stdafx.h"
#include "SetException.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SetException_Impl::metaname = "SetException";

  //
  // SetException_Impl
  //
  SetException_Impl::SetException_Impl (void)
  {
  }

  //
  // SetException_Impl
  //
  SetException_Impl::SetException_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SetException_Impl
  //
  SetException_Impl::~SetException_Impl (void)
  {
  }

  //
  // accept
  //
  void SetException_Impl::accept (Visitor * v)
  {
    v->visit_SetException (this);
  }

  //
  // _create
  //
  SetException SetException_Impl::_create (const Attribute_in parent)
  {
    return ::GAME::Mga::create_object <SetException> (parent, SetException_Impl::metaname);
  }

  //
  // parent_Attribute
  //
  Attribute SetException_Impl::parent_Attribute (void) const
  {
    return ::GAME::Mga::get_parent <Attribute> (this->object_.p);
  }
}

