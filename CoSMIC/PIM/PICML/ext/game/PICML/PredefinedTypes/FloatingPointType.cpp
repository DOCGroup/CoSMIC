// $Id$

#include "stdafx.h"
#include "FloatingPointType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string FloatingPointType_Impl::metaname = "FloatingPointType";

  //
  // FloatingPointType_Impl
  //
  FloatingPointType_Impl::FloatingPointType_Impl (void)
  {
  }

  //
  // FloatingPointType_Impl
  //
  FloatingPointType_Impl::FloatingPointType_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FloatingPointType_Impl
  //
  FloatingPointType_Impl::~FloatingPointType_Impl (void)
  {
  }
}

