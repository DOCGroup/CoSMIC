// $Id$

#include "stdafx.h"
#include "Enum.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/EnumValue.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Enum_Impl::metaname = "Enum";

  //
  // Enum_Impl
  //
  Enum_Impl::Enum_Impl (void)
  {
  }

  //
  // Enum_Impl
  //
  Enum_Impl::Enum_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Enum_Impl
  //
  Enum_Impl::~Enum_Impl (void)
  {
  }

  //
  // accept
  //
  void Enum_Impl::accept (Visitor * v)
  {
    v->visit_Enum (this);
  }

  //
  // get_EnumValues
  //
  size_t Enum_Impl::get_EnumValues (std::vector <EnumValue> & items) const
  {
    return this->children (items);
  }
}

