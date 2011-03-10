// $Id$

#include "stdafx.h"
#include "Jitter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Jitter_Impl::metaname = "Jitter";

  //
  // Jitter_Impl
  //
  Jitter_Impl::Jitter_Impl (void)
  {
  }

  //
  // Jitter_Impl
  //
  Jitter_Impl::Jitter_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Jitter_Impl
  //
  Jitter_Impl::~Jitter_Impl (void)
  {
  }

  //
  // accept
  //
  void Jitter_Impl::accept (Visitor * v)
  {
    v->visit_Jitter (this);
  }
}

