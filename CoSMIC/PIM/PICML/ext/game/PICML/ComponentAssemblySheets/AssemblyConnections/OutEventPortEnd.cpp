// $Id$

#include "stdafx.h"
#include "OutEventPortEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortEnd_Impl::metaname = "OutEventPortEnd";

  //
  // OutEventPortEnd_Impl
  //
  OutEventPortEnd_Impl::OutEventPortEnd_Impl (void)
  {
  }

  //
  // OutEventPortEnd_Impl
  //
  OutEventPortEnd_Impl::OutEventPortEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutEventPortEnd_Impl
  //
  OutEventPortEnd_Impl::~OutEventPortEnd_Impl (void)
  {
  }

  //
  // in_SendsTo_connections
  //
  size_t OutEventPortEnd_Impl::in_SendsTo_connections (std::vector <SendsTo> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_EventSourceDelegate_connections
  //
  size_t OutEventPortEnd_Impl::in_EventSourceDelegate_connections (std::vector <EventSourceDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

