// $Id$

#include "stdafx.h"
#include "ParameterType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ParameterType_Impl::metaname = "ParameterType";

  //
  // ParameterType_Impl
  //
  ParameterType_Impl::ParameterType_Impl (void)
  {
  }

  //
  // ParameterType_Impl
  //
  ParameterType_Impl::ParameterType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ParameterType_Impl
  //
  ParameterType_Impl::~ParameterType_Impl (void)
  {
  }
}

