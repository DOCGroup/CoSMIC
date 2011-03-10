// $Id$

#include "stdafx.h"
#include "SignedIntegerType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SignedIntegerType_Impl::metaname = "SignedIntegerType";

  //
  // SignedIntegerType_Impl
  //
  SignedIntegerType_Impl::SignedIntegerType_Impl (void)
  {
  }

  //
  // SignedIntegerType_Impl
  //
  SignedIntegerType_Impl::SignedIntegerType_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SignedIntegerType_Impl
  //
  SignedIntegerType_Impl::~SignedIntegerType_Impl (void)
  {
  }
}

