// $Id$

#include "StdAfx.h"
#include "OutEventPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "OutEventPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortEnd_Impl::metaname ("OutEventPortEnd");

  //
  // src_SendsTo
  //
  size_t OutEventPortEnd_Impl::src_SendsTo (std::vector <SendsTo> & items) const
  {
    return this->in_connections <SendsTo> (items);
  }

  //
  // src_EventSourceDelegate
  //
  size_t OutEventPortEnd_Impl::src_EventSourceDelegate (std::vector <EventSourceDelegate> & items) const
  {
    return this->in_connections <EventSourceDelegate> (items);
  }
}

