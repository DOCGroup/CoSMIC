// $Id$

#include "stdafx.h"
#include "ConstantType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InterfaceDefinition/Constant.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConstantType_Impl::metaname = "ConstantType";

  //
  // ConstantType_Impl
  //
  ConstantType_Impl::ConstantType_Impl (void)
  {
  }

  //
  // ConstantType_Impl
  //
  ConstantType_Impl::ConstantType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConstantType_Impl
  //
  ConstantType_Impl::~ConstantType_Impl (void)
  {
  }
}

