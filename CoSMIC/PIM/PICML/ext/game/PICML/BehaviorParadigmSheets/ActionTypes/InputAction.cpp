// $Id$

#include "stdafx.h"
#include "InputAction.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InputAction_Impl::metaname = "InputAction";

  //
  // InputAction_Impl
  //
  InputAction_Impl::InputAction_Impl (void)
  {
  }

  //
  // InputAction_Impl
  //
  InputAction_Impl::InputAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InputAction_Impl
  //
  InputAction_Impl::~InputAction_Impl (void)
  {
  }

  //
  // accept
  //
  void InputAction_Impl::accept (Visitor * v)
  {
    v->visit_InputAction (this);
  }
}

