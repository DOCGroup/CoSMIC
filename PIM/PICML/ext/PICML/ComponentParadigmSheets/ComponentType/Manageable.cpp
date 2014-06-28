// $Id$

#include "StdAfx.h"
#include "Manageable.h"

#if !defined (__GAME_INLINE__)
#include "Manageable.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Manageable_Impl::metaname ("Manageable");

  //
  // dst_ManagesComponent
  //
  size_t Manageable_Impl::dst_ManagesComponent (std::vector <ManagesComponent> & items) const
  {
    return this->in_connections <ManagesComponent> (items);
  }
}

