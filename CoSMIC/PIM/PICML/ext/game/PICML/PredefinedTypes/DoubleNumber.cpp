// $Id$

#include "stdafx.h"
#include "DoubleNumber.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DoubleNumber_Impl::metaname = "DoubleNumber";

  //
  // DoubleNumber_Impl
  //
  DoubleNumber_Impl::DoubleNumber_Impl (void)
  {
  }

  //
  // DoubleNumber_Impl
  //
  DoubleNumber_Impl::DoubleNumber_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DoubleNumber_Impl
  //
  DoubleNumber_Impl::~DoubleNumber_Impl (void)
  {
  }

  //
  // accept
  //
  void DoubleNumber_Impl::accept (Visitor * v)
  {
    v->visit_DoubleNumber (this);
  }
}

