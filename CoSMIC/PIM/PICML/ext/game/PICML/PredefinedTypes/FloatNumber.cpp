// $Id$

#include "stdafx.h"
#include "FloatNumber.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string FloatNumber_Impl::metaname = "FloatNumber";

  //
  // FloatNumber_Impl
  //
  FloatNumber_Impl::FloatNumber_Impl (void)
  {
  }

  //
  // FloatNumber_Impl
  //
  FloatNumber_Impl::FloatNumber_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FloatNumber_Impl
  //
  FloatNumber_Impl::~FloatNumber_Impl (void)
  {
  }

  //
  // accept
  //
  void FloatNumber_Impl::accept (Visitor * v)
  {
    v->visit_FloatNumber (this);
  }
}

