// $Id$

#include "stdafx.h"
#include "CommonPortAttrs.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CommonPortAttrs_Impl::metaname = "CommonPortAttrs";

  //
  // CommonPortAttrs_Impl
  //
  CommonPortAttrs_Impl::CommonPortAttrs_Impl (void)
  {
  }

  //
  // CommonPortAttrs_Impl
  //
  CommonPortAttrs_Impl::CommonPortAttrs_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CommonPortAttrs_Impl
  //
  CommonPortAttrs_Impl::~CommonPortAttrs_Impl (void)
  {
  }
}

