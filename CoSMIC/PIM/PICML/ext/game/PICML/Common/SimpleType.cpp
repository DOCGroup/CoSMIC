// $Id$

#include "stdafx.h"
#include "SimpleType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Common/DataValue.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SimpleType_Impl::metaname = "SimpleType";

  //
  // SimpleType_Impl
  //
  SimpleType_Impl::SimpleType_Impl (void)
  {
  }

  //
  // SimpleType_Impl
  //
  SimpleType_Impl::SimpleType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SimpleType_Impl
  //
  SimpleType_Impl::~SimpleType_Impl (void)
  {
  }
}

