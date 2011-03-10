// $Id$

#include "stdafx.h"
#include "Manageable.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Manageable_Impl::metaname = "Manageable";

  //
  // Manageable_Impl
  //
  Manageable_Impl::Manageable_Impl (void)
  {
  }

  //
  // Manageable_Impl
  //
  Manageable_Impl::Manageable_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Manageable_Impl
  //
  Manageable_Impl::~Manageable_Impl (void)
  {
  }

  //
  // in_ManagesComponent_connections
  //
  size_t Manageable_Impl::in_ManagesComponent_connections (std::vector <ManagesComponent> & conns) const
  {
    return this->in_connections (conns);
  }
}

