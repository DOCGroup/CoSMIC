// $Id$

#include "stdafx.h"
#include "UnsignedIntegerType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string UnsignedIntegerType_Impl::metaname = "UnsignedIntegerType";

  //
  // UnsignedIntegerType_Impl
  //
  UnsignedIntegerType_Impl::UnsignedIntegerType_Impl (void)
  {
  }

  //
  // UnsignedIntegerType_Impl
  //
  UnsignedIntegerType_Impl::UnsignedIntegerType_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~UnsignedIntegerType_Impl
  //
  UnsignedIntegerType_Impl::~UnsignedIntegerType_Impl (void)
  {
  }
}

