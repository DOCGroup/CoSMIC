// $Id$

#include "stdafx.h"
#include "InEventPortEnd.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/SendsTo.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortEnd_Impl::metaname = "InEventPortEnd";

  //
  // InEventPortEnd_Impl
  //
  InEventPortEnd_Impl::InEventPortEnd_Impl (void)
  {
  }

  //
  // InEventPortEnd_Impl
  //
  InEventPortEnd_Impl::InEventPortEnd_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InEventPortEnd_Impl
  //
  InEventPortEnd_Impl::~InEventPortEnd_Impl (void)
  {
  }

  //
  // in_EventSinkDelegate_connections
  //
  size_t InEventPortEnd_Impl::in_EventSinkDelegate_connections (std::vector <EventSinkDelegate> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_SendsTo_connections
  //
  size_t InEventPortEnd_Impl::in_SendsTo_connections (std::vector <SendsTo> & conns) const
  {
    return this->in_connections (conns);
  }
}

