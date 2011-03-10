// $Id$

#include "stdafx.h"
#include "EnumValue.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Enum.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EnumValue_Impl::metaname = "EnumValue";

  //
  // EnumValue_Impl
  //
  EnumValue_Impl::EnumValue_Impl (void)
  {
  }

  //
  // EnumValue_Impl
  //
  EnumValue_Impl::EnumValue_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EnumValue_Impl
  //
  EnumValue_Impl::~EnumValue_Impl (void)
  {
  }

  //
  // accept
  //
  void EnumValue_Impl::accept (Visitor * v)
  {
    v->visit_EnumValue (this);
  }

  //
  // _create
  //
  EnumValue EnumValue_Impl::_create (const Enum_in parent)
  {
    return ::GAME::Mga::create_object <EnumValue> (parent, EnumValue_Impl::metaname);
  }

  //
  // parent_Enum
  //
  Enum EnumValue_Impl::parent_Enum (void) const
  {
    return ::GAME::Mga::get_parent <Enum> (this->object_.p);
  }
}

