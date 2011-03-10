// $Id$

#include "stdafx.h"
#include "ArrayMember.h"

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
  const std::string ArrayMember_Impl::metaname = "ArrayMember";

  //
  // ArrayMember_Impl
  //
  ArrayMember_Impl::ArrayMember_Impl (void)
  {
  }

  //
  // ArrayMember_Impl
  //
  ArrayMember_Impl::ArrayMember_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArrayMember_Impl
  //
  ArrayMember_Impl::~ArrayMember_Impl (void)
  {
  }

  //
  // accept
  //
  void ArrayMember_Impl::accept (Visitor * v)
  {
    v->visit_ArrayMember (this);
  }

  //
  // Size
  //
  void ArrayMember_Impl::Size (long val)
  {
    static const std::string attr_Size ("Size");
    this->attribute (attr_Size)->int_value (val);
  }

  //
  // Size
  //
  long ArrayMember_Impl::Size (void) const
  {
    static const std::string attr_Size ("Size");
    return this->attribute (attr_Size)->int_value ();
  }
}

