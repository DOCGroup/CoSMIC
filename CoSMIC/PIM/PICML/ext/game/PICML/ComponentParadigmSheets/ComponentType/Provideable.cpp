// $Id$

#include "stdafx.h"
#include "Provideable.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Provideable_Impl::metaname = "Provideable";

  //
  // Provideable_Impl
  //
  Provideable_Impl::Provideable_Impl (void)
  {
  }

  //
  // Provideable_Impl
  //
  Provideable_Impl::Provideable_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Provideable_Impl
  //
  Provideable_Impl::~Provideable_Impl (void)
  {
  }
}

