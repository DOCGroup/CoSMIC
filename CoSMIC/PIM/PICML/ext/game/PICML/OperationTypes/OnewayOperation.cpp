// $Id$

#include "stdafx.h"
#include "OnewayOperation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OnewayOperation_Impl::metaname = "OnewayOperation";

  //
  // OnewayOperation_Impl
  //
  OnewayOperation_Impl::OnewayOperation_Impl (void)
  {
  }

  //
  // OnewayOperation_Impl
  //
  OnewayOperation_Impl::OnewayOperation_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OnewayOperation_Impl
  //
  OnewayOperation_Impl::~OnewayOperation_Impl (void)
  {
  }

  //
  // accept
  //
  void OnewayOperation_Impl::accept (Visitor * v)
  {
    v->visit_OnewayOperation (this);
  }
}

