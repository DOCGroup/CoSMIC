// $Id$

#include "stdafx.h"
#include "DoWhileState.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DoWhileState_Impl::metaname = "DoWhileState";

  //
  // DoWhileState_Impl
  //
  DoWhileState_Impl::DoWhileState_Impl (void)
  {
  }

  //
  // DoWhileState_Impl
  //
  DoWhileState_Impl::DoWhileState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DoWhileState_Impl
  //
  DoWhileState_Impl::~DoWhileState_Impl (void)
  {
  }

  //
  // accept
  //
  void DoWhileState_Impl::accept (Visitor * v)
  {
    v->visit_DoWhileState (this);
  }
}

