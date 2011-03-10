// $Id$

#include "stdafx.h"
#include "MultiInputAction.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MultiInputAction_Impl::metaname = "MultiInputAction";

  //
  // MultiInputAction_Impl
  //
  MultiInputAction_Impl::MultiInputAction_Impl (void)
  {
  }

  //
  // MultiInputAction_Impl
  //
  MultiInputAction_Impl::MultiInputAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MultiInputAction_Impl
  //
  MultiInputAction_Impl::~MultiInputAction_Impl (void)
  {
  }

  //
  // accept
  //
  void MultiInputAction_Impl::accept (Visitor * v)
  {
    v->visit_MultiInputAction (this);
  }
}

