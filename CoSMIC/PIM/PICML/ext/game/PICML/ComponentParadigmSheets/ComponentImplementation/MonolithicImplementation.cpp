// $Id$

#include "stdafx.h"
#include "MonolithicImplementation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithicImplementation_Impl::metaname = "MonolithicImplementation";

  //
  // MonolithicImplementation_Impl
  //
  MonolithicImplementation_Impl::MonolithicImplementation_Impl (void)
  {
  }

  //
  // MonolithicImplementation_Impl
  //
  MonolithicImplementation_Impl::MonolithicImplementation_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MonolithicImplementation_Impl
  //
  MonolithicImplementation_Impl::~MonolithicImplementation_Impl (void)
  {
  }

  //
  // accept
  //
  void MonolithicImplementation_Impl::accept (Visitor * v)
  {
    v->visit_MonolithicImplementation (this);
  }
}

