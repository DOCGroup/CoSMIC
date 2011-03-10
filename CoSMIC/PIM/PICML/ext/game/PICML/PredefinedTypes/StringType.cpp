// $Id$

#include "stdafx.h"
#include "StringType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string StringType_Impl::metaname = "StringType";

  //
  // StringType_Impl
  //
  StringType_Impl::StringType_Impl (void)
  {
  }

  //
  // StringType_Impl
  //
  StringType_Impl::StringType_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~StringType_Impl
  //
  StringType_Impl::~StringType_Impl (void)
  {
  }
}

