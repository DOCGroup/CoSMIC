// $Id$

#include "stdafx.h"
#include "LongInteger.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LongInteger_Impl::metaname = "LongInteger";

  //
  // LongInteger_Impl
  //
  LongInteger_Impl::LongInteger_Impl (void)
  {
  }

  //
  // LongInteger_Impl
  //
  LongInteger_Impl::LongInteger_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LongInteger_Impl
  //
  LongInteger_Impl::~LongInteger_Impl (void)
  {
  }

  //
  // accept
  //
  void LongInteger_Impl::accept (Visitor * v)
  {
    v->visit_LongInteger (this);
  }
}

