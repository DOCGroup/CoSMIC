// $Id$

#include "stdafx.h"
#include "NamedType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string NamedType_Impl::metaname = "NamedType";

  //
  // NamedType_Impl
  //
  NamedType_Impl::NamedType_Impl (void)
  {
  }

  //
  // NamedType_Impl
  //
  NamedType_Impl::NamedType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NamedType_Impl
  //
  NamedType_Impl::~NamedType_Impl (void)
  {
  }
}

