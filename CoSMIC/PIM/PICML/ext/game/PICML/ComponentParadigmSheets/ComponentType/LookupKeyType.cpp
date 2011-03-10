// $Id$

#include "stdafx.h"
#include "LookupKeyType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/LookupKey.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LookupKeyType_Impl::metaname = "LookupKeyType";

  //
  // LookupKeyType_Impl
  //
  LookupKeyType_Impl::LookupKeyType_Impl (void)
  {
  }

  //
  // LookupKeyType_Impl
  //
  LookupKeyType_Impl::LookupKeyType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LookupKeyType_Impl
  //
  LookupKeyType_Impl::~LookupKeyType_Impl (void)
  {
  }
}

