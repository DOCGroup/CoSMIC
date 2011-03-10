// $Id$

#include "stdafx.h"
#include "InputEffect.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InputEffect_Impl::metaname = "InputEffect";

  //
  // InputEffect_Impl
  //
  InputEffect_Impl::InputEffect_Impl (void)
  {
  }

  //
  // InputEffect_Impl
  //
  InputEffect_Impl::InputEffect_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InputEffect_Impl
  //
  InputEffect_Impl::~InputEffect_Impl (void)
  {
  }

  //
  // accept
  //
  void InputEffect_Impl::accept (Visitor * v)
  {
    v->visit_InputEffect (this);
  }
}

