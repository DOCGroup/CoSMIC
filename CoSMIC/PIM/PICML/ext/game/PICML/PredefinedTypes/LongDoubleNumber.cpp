// $Id$

#include "stdafx.h"
#include "LongDoubleNumber.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LongDoubleNumber_Impl::metaname = "LongDoubleNumber";

  //
  // LongDoubleNumber_Impl
  //
  LongDoubleNumber_Impl::LongDoubleNumber_Impl (void)
  {
  }

  //
  // LongDoubleNumber_Impl
  //
  LongDoubleNumber_Impl::LongDoubleNumber_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LongDoubleNumber_Impl
  //
  LongDoubleNumber_Impl::~LongDoubleNumber_Impl (void)
  {
  }

  //
  // accept
  //
  void LongDoubleNumber_Impl::accept (Visitor * v)
  {
    v->visit_LongDoubleNumber (this);
  }
}

