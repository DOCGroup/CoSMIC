// $Id$

#include "StdAfx.h"
#include "Implemenation.h"

#if !defined (__GAME_INLINE__)
#include "Implemenation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Implemenation_Impl::metaname ("Implemenation");

  //
  // src_InfoProperty
  //
  size_t Implemenation_Impl::src_InfoProperty (std::vector <InfoProperty> & items) const
  {
    return this->in_connections <InfoProperty> (items);
  }

  //
  // src_ConfigProperty
  //
  size_t Implemenation_Impl::src_ConfigProperty (std::vector <ConfigProperty> & items) const
  {
    return this->in_connections <ConfigProperty> (items);
  }
}

