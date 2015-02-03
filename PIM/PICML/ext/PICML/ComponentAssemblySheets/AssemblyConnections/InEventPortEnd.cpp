// $Id$

#include "StdAfx.h"
#include "InEventPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "InEventPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortEnd_Impl::metaname ("InEventPortEnd");

  //
  // is_abstract
  //
  const bool InEventPortEnd_Impl::is_abstract (1);

  //
  // dst_of_SendsTo
  //
  size_t InEventPortEnd_Impl::dst_of_SendsTo (std::vector <SendsTo> & items) const
  {
    return this->in_connections <SendsTo> (items);
  }

  //
  // dst_of_SendsTo
  //
  GAME::Mga::Collection_T <SendsTo> InEventPortEnd_Impl::dst_of_SendsTo (void) const
  {
    return this->in_connections <SendsTo> ("dst");
  }

  //
  // dst_of_EventSinkDelegate
  //
  size_t InEventPortEnd_Impl::dst_of_EventSinkDelegate (std::vector <EventSinkDelegate> & items) const
  {
    return this->in_connections <EventSinkDelegate> (items);
  }

  //
  // dst_of_EventSinkDelegate
  //
  GAME::Mga::Collection_T <EventSinkDelegate> InEventPortEnd_Impl::dst_of_EventSinkDelegate (void) const
  {
    return this->in_connections <EventSinkDelegate> ("dst");
  }
}

