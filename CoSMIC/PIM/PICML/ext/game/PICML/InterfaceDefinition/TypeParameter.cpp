// $Id$

#include "stdafx.h"
#include "TypeParameter.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TypeParameter_Impl::metaname = "TypeParameter";

  //
  // TypeParameter_Impl
  //
  TypeParameter_Impl::TypeParameter_Impl (void)
  {
  }

  //
  // TypeParameter_Impl
  //
  TypeParameter_Impl::TypeParameter_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TypeParameter_Impl
  //
  TypeParameter_Impl::~TypeParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void TypeParameter_Impl::accept (Visitor * v)
  {
    v->visit_TypeParameter (this);
  }

  //
  // Type
  //
  void TypeParameter_Impl::Type (const std::string & val)
  {
    static const std::string attr_Type ("Type");
    this->attribute (attr_Type)->string_value (val);
  }

  //
  // Type
  //
  std::string TypeParameter_Impl::Type (void) const
  {
    static const std::string attr_Type ("Type");
    return this->attribute (attr_Type)->string_value ();
  }
}

