// $Id$

#include "stdafx.h"
#include "WideString.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WideString_Impl::metaname = "WideString";

  //
  // WideString_Impl
  //
  WideString_Impl::WideString_Impl (void)
  {
  }

  //
  // WideString_Impl
  //
  WideString_Impl::WideString_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WideString_Impl
  //
  WideString_Impl::~WideString_Impl (void)
  {
  }

  //
  // accept
  //
  void WideString_Impl::accept (Visitor * v)
  {
    v->visit_WideString (this);
  }
}

