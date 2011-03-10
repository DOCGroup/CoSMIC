// $Id$

#include "stdafx.h"
#include "Effect.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Effect_Impl::metaname = "Effect";

  //
  // Effect_Impl
  //
  Effect_Impl::Effect_Impl (void)
  {
  }

  //
  // Effect_Impl
  //
  Effect_Impl::Effect_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Effect_Impl
  //
  Effect_Impl::~Effect_Impl (void)
  {
  }

  //
  // accept
  //
  void Effect_Impl::accept (Visitor * v)
  {
    v->visit_Effect (this);
  }
}

