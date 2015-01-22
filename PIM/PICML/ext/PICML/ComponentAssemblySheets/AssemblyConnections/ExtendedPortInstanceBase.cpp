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
  // src_of_ExtendedDelegate
  //
  size_t ExtendedPortInstanceBase_Impl::src_of_ExtendedDelegate (std::vector <ExtendedDelegate> & items) const
  {
    return this->in_connections <ExtendedDelegate> (items);
  }

  //
  // src_of_ExtendedDelegate
  //
  GAME::Mga::Collection_T <ExtendedDelegate> ExtendedPortInstanceBase_Impl::src_of_ExtendedDelegate (void) const
  {
    return this->in_connections <ExtendedDelegate> ("src");
  }
}

