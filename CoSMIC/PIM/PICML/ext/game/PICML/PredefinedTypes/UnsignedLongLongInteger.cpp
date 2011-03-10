// $Id$

#include "stdafx.h"
#include "UnsignedLongLongInteger.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string UnsignedLongLongInteger_Impl::metaname = "UnsignedLongLongInteger";

  //
  // UnsignedLongLongInteger_Impl
  //
  UnsignedLongLongInteger_Impl::UnsignedLongLongInteger_Impl (void)
  {
  }

  //
  // UnsignedLongLongInteger_Impl
  //
  UnsignedLongLongInteger_Impl::UnsignedLongLongInteger_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~UnsignedLongLongInteger_Impl
  //
  UnsignedLongLongInteger_Impl::~UnsignedLongLongInteger_Impl (void)
  {
  }

  //
  // accept
  //
  void UnsignedLongLongInteger_Impl::accept (Visitor * v)
  {
    v->visit_UnsignedLongLongInteger (this);
  }
}

