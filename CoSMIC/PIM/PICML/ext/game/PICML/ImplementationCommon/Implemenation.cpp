// $Id$

#include "stdafx.h"
#include "Implemenation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Implemenation_Impl::metaname = "Implemenation";

  //
  // Implemenation_Impl
  //
  Implemenation_Impl::Implemenation_Impl (void)
  {
  }

  //
  // Implemenation_Impl
  //
  Implemenation_Impl::Implemenation_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Implemenation_Impl
  //
  Implemenation_Impl::~Implemenation_Impl (void)
  {
  }

  //
  // in_InfoProperty_connections
  //
  size_t Implemenation_Impl::in_InfoProperty_connections (std::vector <InfoProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ConfigProperty_connections
  //
  size_t Implemenation_Impl::in_ConfigProperty_connections (std::vector <ConfigProperty> & conns) const
  {
    return this->in_connections (conns);
  }
}

