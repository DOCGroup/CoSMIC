// $Id$

#include "stdafx.h"
#include "ValueObject.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ValueObject_Impl::metaname = "ValueObject";

  //
  // ValueObject_Impl
  //
  ValueObject_Impl::ValueObject_Impl (void)
  {
  }

  //
  // ValueObject_Impl
  //
  ValueObject_Impl::ValueObject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ValueObject_Impl
  //
  ValueObject_Impl::~ValueObject_Impl (void)
  {
  }

  //
  // accept
  //
  void ValueObject_Impl::accept (Visitor * v)
  {
    v->visit_ValueObject (this);
  }
}

