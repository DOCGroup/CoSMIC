// $Id$

#include "stdafx.h"
#include "Average.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Average_Impl::metaname = "Average";

  //
  // Average_Impl
  //
  Average_Impl::Average_Impl (void)
  {
  }

  //
  // Average_Impl
  //
  Average_Impl::Average_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Average_Impl
  //
  Average_Impl::~Average_Impl (void)
  {
  }

  //
  // accept
  //
  void Average_Impl::accept (Visitor * v)
  {
    v->visit_Average (this);
  }
}

