#include "StdAfx.h"
#include "OutEventPortEnd.h"

#if !defined (__GAME_INLINE__)
#include "OutEventPortEnd.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortEnd_Impl::metaname ("OutEventPortEnd");

  //
  // is_abstract
  //
  const bool OutEventPortEnd_Impl::is_abstract = true;

  //
  // src_of_EventSourceDelegate
  //
  size_t OutEventPortEnd_Impl::src_of_EventSourceDelegate (std::vector <EventSourceDelegate> & items) const
  {
    return this->in_connections <EventSourceDelegate> (items);
  }

  //
  // src_of_EventSourceDelegate
  //
  GAME::Mga::Collection_T <EventSourceDelegate> OutEventPortEnd_Impl::src_of_EventSourceDelegate (void) const
  {
    return this->in_connections <EventSourceDelegate> ("src");
  }

  //
  // src_of_SendsTo
  //
  size_t OutEventPortEnd_Impl::src_of_SendsTo (std::vector <SendsTo> & items) const
  {
    return this->in_connections <SendsTo> (items);
  }

  //
  // src_of_SendsTo
  //
  GAME::Mga::Collection_T <SendsTo> OutEventPortEnd_Impl::src_of_SendsTo (void) const
  {
    return this->in_connections <SendsTo> ("src");
  }
}

