// $Id$

#include "stdafx.h"
#include "Minimum.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Minimum_Impl::metaname = "Minimum";

  //
  // Minimum_Impl
  //
  Minimum_Impl::Minimum_Impl (void)
  {
  }

  //
  // Minimum_Impl
  //
  Minimum_Impl::Minimum_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Minimum_Impl
  //
  Minimum_Impl::~Minimum_Impl (void)
  {
  }

  //
  // accept
  //
  void Minimum_Impl::accept (Visitor * v)
  {
    v->visit_Minimum (this);
  }
}

