// $Id$

#include "StdAfx.h"
#include "MirrorPortInstanceBase.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPortInstanceBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortInstanceBase_Impl::metaname ("MirrorPortInstanceBase");

  //
  // src_MirrorDelegate
  //
  size_t MirrorPortInstanceBase_Impl::src_MirrorDelegate (std::vector <MirrorDelegate> & items) const
  {
    return this->in_connections <MirrorDelegate> (items);
  }
}

