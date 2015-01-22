// $Id$

#include "StdAfx.h"
#include "ExternalPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "ExternalPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalPortEnd_Impl::metaname ("ExternalPortEnd");

  //
  // dst_of_ExternalDelegate
  //
  size_t ExternalPortEnd_Impl::dst_of_ExternalDelegate (std::vector <ExternalDelegate> & items) const
  {
    return this->in_connections <ExternalDelegate> (items);
  }

  //
  // dst_of_ExternalDelegate
  //
  GAME::Mga::Collection_T <ExternalDelegate> ExternalPortEnd_Impl::dst_of_ExternalDelegate (void) const
  {
    return this->in_connections <ExternalDelegate> ("dst");
  }
}

