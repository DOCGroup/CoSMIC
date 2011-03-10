// $Id$

#include "stdafx.h"
#include "ShortInteger.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ShortInteger_Impl::metaname = "ShortInteger";

  //
  // ShortInteger_Impl
  //
  ShortInteger_Impl::ShortInteger_Impl (void)
  {
  }

  //
  // ShortInteger_Impl
  //
  ShortInteger_Impl::ShortInteger_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ShortInteger_Impl
  //
  ShortInteger_Impl::~ShortInteger_Impl (void)
  {
  }

  //
  // accept
  //
  void ShortInteger_Impl::accept (Visitor * v)
  {
    v->visit_ShortInteger (this);
  }
}

