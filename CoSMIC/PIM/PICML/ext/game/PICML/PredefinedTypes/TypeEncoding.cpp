// $Id$

#include "stdafx.h"
#include "TypeEncoding.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TypeEncoding_Impl::metaname = "TypeEncoding";

  //
  // TypeEncoding_Impl
  //
  TypeEncoding_Impl::TypeEncoding_Impl (void)
  {
  }

  //
  // TypeEncoding_Impl
  //
  TypeEncoding_Impl::TypeEncoding_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TypeEncoding_Impl
  //
  TypeEncoding_Impl::~TypeEncoding_Impl (void)
  {
  }

  //
  // accept
  //
  void TypeEncoding_Impl::accept (Visitor * v)
  {
    v->visit_TypeEncoding (this);
  }
}

