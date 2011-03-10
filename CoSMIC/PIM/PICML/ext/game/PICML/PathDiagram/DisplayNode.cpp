// $Id$

#include "stdafx.h"
#include "DisplayNode.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DisplayNode_Impl::metaname = "DisplayNode";

  //
  // DisplayNode_Impl
  //
  DisplayNode_Impl::DisplayNode_Impl (void)
  {
  }

  //
  // DisplayNode_Impl
  //
  DisplayNode_Impl::DisplayNode_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DisplayNode_Impl
  //
  DisplayNode_Impl::~DisplayNode_Impl (void)
  {
  }

  //
  // accept
  //
  void DisplayNode_Impl::accept (Visitor * v)
  {
    v->visit_DisplayNode (this);
  }
}

