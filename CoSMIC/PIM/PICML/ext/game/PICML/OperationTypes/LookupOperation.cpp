// $Id$

#include "stdafx.h"
#include "LookupOperation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LookupOperation_Impl::metaname = "LookupOperation";

  //
  // LookupOperation_Impl
  //
  LookupOperation_Impl::LookupOperation_Impl (void)
  {
  }

  //
  // LookupOperation_Impl
  //
  LookupOperation_Impl::LookupOperation_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LookupOperation_Impl
  //
  LookupOperation_Impl::~LookupOperation_Impl (void)
  {
  }

  //
  // accept
  //
  void LookupOperation_Impl::accept (Visitor * v)
  {
    v->visit_LookupOperation (this);
  }
}

