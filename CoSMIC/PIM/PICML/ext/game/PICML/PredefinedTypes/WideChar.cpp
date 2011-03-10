// $Id$

#include "stdafx.h"
#include "WideChar.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WideChar_Impl::metaname = "WideChar";

  //
  // WideChar_Impl
  //
  WideChar_Impl::WideChar_Impl (void)
  {
  }

  //
  // WideChar_Impl
  //
  WideChar_Impl::WideChar_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WideChar_Impl
  //
  WideChar_Impl::~WideChar_Impl (void)
  {
  }

  //
  // accept
  //
  void WideChar_Impl::accept (Visitor * v)
  {
    v->visit_WideChar (this);
  }
}

