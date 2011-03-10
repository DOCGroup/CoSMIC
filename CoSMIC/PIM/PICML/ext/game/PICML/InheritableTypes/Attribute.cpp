// $Id$

#include "stdafx.h"
#include "Attribute.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/SetException.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Attribute_Impl::metaname = "Attribute";

  //
  // Attribute_Impl
  //
  Attribute_Impl::Attribute_Impl (void)
  {
  }

  //
  // Attribute_Impl
  //
  Attribute_Impl::Attribute_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Attribute_Impl
  //
  Attribute_Impl::~Attribute_Impl (void)
  {
  }

  //
  // accept
  //
  void Attribute_Impl::accept (Visitor * v)
  {
    v->visit_Attribute (this);
  }

  //
  // get_SetExceptions
  //
  size_t Attribute_Impl::get_SetExceptions (std::vector <SetException> & items) const
  {
    return this->children (items);
  }
}

