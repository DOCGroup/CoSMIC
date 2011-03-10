// $Id$

#include "stdafx.h"
#include "UnsignedShortInteger.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string UnsignedShortInteger_Impl::metaname = "UnsignedShortInteger";

  //
  // UnsignedShortInteger_Impl
  //
  UnsignedShortInteger_Impl::UnsignedShortInteger_Impl (void)
  {
  }

  //
  // UnsignedShortInteger_Impl
  //
  UnsignedShortInteger_Impl::UnsignedShortInteger_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~UnsignedShortInteger_Impl
  //
  UnsignedShortInteger_Impl::~UnsignedShortInteger_Impl (void)
  {
  }

  //
  // accept
  //
  void UnsignedShortInteger_Impl::accept (Visitor * v)
  {
    v->visit_UnsignedShortInteger (this);
  }
}

