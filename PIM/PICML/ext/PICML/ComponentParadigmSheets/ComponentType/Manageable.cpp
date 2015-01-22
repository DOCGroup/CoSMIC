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
  // dst_of_ManagesComponent
  //
  size_t Manageable_Impl::dst_of_ManagesComponent (std::vector <ManagesComponent> & items) const
  {
    return this->in_connections <ManagesComponent> (items);
  }

  //
  // dst_of_ManagesComponent
  //
  GAME::Mga::Collection_T <ManagesComponent> Manageable_Impl::dst_of_ManagesComponent (void) const
  {
    return this->in_connections <ManagesComponent> ("dst");
  }
}

