// $Id$

#include "stdafx.h"
#include "ComplexType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Common/ComplexTypeReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComplexType_Impl::metaname = "ComplexType";

  //
  // ComplexType_Impl
  //
  ComplexType_Impl::ComplexType_Impl (void)
  {
  }

  //
  // ComplexType_Impl
  //
  ComplexType_Impl::ComplexType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComplexType_Impl
  //
  ComplexType_Impl::~ComplexType_Impl (void)
  {
  }
}

