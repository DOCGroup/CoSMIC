// $Id$

#include "stdafx.h"
#include "WhileState.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WhileState_Impl::metaname = "WhileState";

  //
  // WhileState_Impl
  //
  WhileState_Impl::WhileState_Impl (void)
  {
  }

  //
  // WhileState_Impl
  //
  WhileState_Impl::WhileState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WhileState_Impl
  //
  WhileState_Impl::~WhileState_Impl (void)
  {
  }

  //
  // accept
  //
  void WhileState_Impl::accept (Visitor * v)
  {
    v->visit_WhileState (this);
  }
}

