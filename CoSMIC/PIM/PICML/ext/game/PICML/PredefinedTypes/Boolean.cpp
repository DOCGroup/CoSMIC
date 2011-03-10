// $Id$

#include "stdafx.h"
#include "Boolean.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Boolean_Impl::metaname = "Boolean";

  //
  // Boolean_Impl
  //
  Boolean_Impl::Boolean_Impl (void)
  {
  }

  //
  // Boolean_Impl
  //
  Boolean_Impl::Boolean_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Boolean_Impl
  //
  Boolean_Impl::~Boolean_Impl (void)
  {
  }

  //
  // accept
  //
  void Boolean_Impl::accept (Visitor * v)
  {
    v->visit_Boolean (this);
  }
}

