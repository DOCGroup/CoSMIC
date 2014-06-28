// $Id$

#include "StdAfx.h"
#include "ExtendedPortInstanceBase.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPortInstanceBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortInstanceBase_Impl::metaname ("ExtendedPortInstanceBase");

  //
  // src_ExtendedDelegate
  //
  size_t ExtendedPortInstanceBase_Impl::src_ExtendedDelegate (std::vector <ExtendedDelegate> & items) const
  {
    return this->in_connections <ExtendedDelegate> (items);
  }
}

