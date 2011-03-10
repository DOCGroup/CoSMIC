// $Id$

#include "stdafx.h"
#include "OutEventPortDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortDelegate_Impl::metaname = "OutEventPortDelegate";

  //
  // OutEventPortDelegate_Impl
  //
  OutEventPortDelegate_Impl::OutEventPortDelegate_Impl (void)
  {
  }

  //
  // OutEventPortDelegate_Impl
  //
  OutEventPortDelegate_Impl::OutEventPortDelegate_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutEventPortDelegate_Impl
  //
  OutEventPortDelegate_Impl::~OutEventPortDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void OutEventPortDelegate_Impl::accept (Visitor * v)
  {
    v->visit_OutEventPortDelegate (this);
  }

  //
  // in_EventSourceDelegate_connections
  //
  size_t OutEventPortDelegate_Impl::in_EventSourceDelegate_connections (std::vector <EventSourceDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

