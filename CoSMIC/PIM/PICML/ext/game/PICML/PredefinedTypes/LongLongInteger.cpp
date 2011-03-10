// $Id$

#include "stdafx.h"
#include "LongLongInteger.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LongLongInteger_Impl::metaname = "LongLongInteger";

  //
  // LongLongInteger_Impl
  //
  LongLongInteger_Impl::LongLongInteger_Impl (void)
  {
  }

  //
  // LongLongInteger_Impl
  //
  LongLongInteger_Impl::LongLongInteger_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LongLongInteger_Impl
  //
  LongLongInteger_Impl::~LongLongInteger_Impl (void)
  {
  }

  //
  // accept
  //
  void LongLongInteger_Impl::accept (Visitor * v)
  {
    v->visit_LongLongInteger (this);
  }
}

