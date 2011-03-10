// $Id$

#include "stdafx.h"
#include "String.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string String_Impl::metaname = "String";

  //
  // String_Impl
  //
  String_Impl::String_Impl (void)
  {
  }

  //
  // String_Impl
  //
  String_Impl::String_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~String_Impl
  //
  String_Impl::~String_Impl (void)
  {
  }

  //
  // accept
  //
  void String_Impl::accept (Visitor * v)
  {
    v->visit_String (this);
  }
}

