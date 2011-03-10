// $Id$

#include "stdafx.h"
#include "TypeKind.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TypeKind_Impl::metaname = "TypeKind";

  //
  // TypeKind_Impl
  //
  TypeKind_Impl::TypeKind_Impl (void)
  {
  }

  //
  // TypeKind_Impl
  //
  TypeKind_Impl::TypeKind_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TypeKind_Impl
  //
  TypeKind_Impl::~TypeKind_Impl (void)
  {
  }

  //
  // accept
  //
  void TypeKind_Impl::accept (Visitor * v)
  {
    v->visit_TypeKind (this);
  }
}

