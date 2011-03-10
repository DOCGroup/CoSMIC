// $Id$

#include "stdafx.h"
#include "FactoryOperation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string FactoryOperation_Impl::metaname = "FactoryOperation";

  //
  // FactoryOperation_Impl
  //
  FactoryOperation_Impl::FactoryOperation_Impl (void)
  {
  }

  //
  // FactoryOperation_Impl
  //
  FactoryOperation_Impl::FactoryOperation_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FactoryOperation_Impl
  //
  FactoryOperation_Impl::~FactoryOperation_Impl (void)
  {
  }

  //
  // accept
  //
  void FactoryOperation_Impl::accept (Visitor * v)
  {
    v->visit_FactoryOperation (this);
  }
}

