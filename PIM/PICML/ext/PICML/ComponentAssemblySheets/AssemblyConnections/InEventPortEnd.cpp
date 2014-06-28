// $Id$

#include "StdAfx.h"
#include "InEventPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "InEventPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortEnd_Impl::metaname ("InEventPortEnd");

  //
  // dst_EventSinkDelegate
  //
  size_t InEventPortEnd_Impl::dst_EventSinkDelegate (std::vector <EventSinkDelegate> & items) const
  {
    return this->in_connections <EventSinkDelegate> (items);
  }

  //
  // dst_SendsTo
  //
  size_t InEventPortEnd_Impl::dst_SendsTo (std::vector <SendsTo> & items) const
  {
    return this->in_connections <SendsTo> (items);
  }
}

