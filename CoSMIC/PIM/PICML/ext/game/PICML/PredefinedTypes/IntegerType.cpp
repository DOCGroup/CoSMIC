// $Id$

#include "stdafx.h"
#include "IntegerType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string IntegerType_Impl::metaname = "IntegerType";

  //
  // IntegerType_Impl
  //
  IntegerType_Impl::IntegerType_Impl (void)
  {
  }

  //
  // IntegerType_Impl
  //
  IntegerType_Impl::IntegerType_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~IntegerType_Impl
  //
  IntegerType_Impl::~IntegerType_Impl (void)
  {
  }
}

