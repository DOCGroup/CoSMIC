// $Id$

#include "stdafx.h"
#include "UnsignedLongInteger.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string UnsignedLongInteger_Impl::metaname = "UnsignedLongInteger";

  //
  // UnsignedLongInteger_Impl
  //
  UnsignedLongInteger_Impl::UnsignedLongInteger_Impl (void)
  {
  }

  //
  // UnsignedLongInteger_Impl
  //
  UnsignedLongInteger_Impl::UnsignedLongInteger_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~UnsignedLongInteger_Impl
  //
  UnsignedLongInteger_Impl::~UnsignedLongInteger_Impl (void)
  {
  }

  //
  // accept
  //
  void UnsignedLongInteger_Impl::accept (Visitor * v)
  {
    v->visit_UnsignedLongInteger (this);
  }
}

