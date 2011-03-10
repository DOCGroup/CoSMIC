// $Id$

#include "stdafx.h"
#include "CharType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CharType_Impl::metaname = "CharType";

  //
  // CharType_Impl
  //
  CharType_Impl::CharType_Impl (void)
  {
  }

  //
  // CharType_Impl
  //
  CharType_Impl::CharType_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CharType_Impl
  //
  CharType_Impl::~CharType_Impl (void)
  {
  }
}

