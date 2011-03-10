// $Id$

#include "stdafx.h"
#include "InEventPortDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortDelegate_Impl::metaname = "InEventPortDelegate";

  //
  // InEventPortDelegate_Impl
  //
  InEventPortDelegate_Impl::InEventPortDelegate_Impl (void)
  {
  }

  //
  // InEventPortDelegate_Impl
  //
  InEventPortDelegate_Impl::InEventPortDelegate_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InEventPortDelegate_Impl
  //
  InEventPortDelegate_Impl::~InEventPortDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void InEventPortDelegate_Impl::accept (Visitor * v)
  {
    v->visit_InEventPortDelegate (this);
  }

  //
  // in_EventSinkDelegate_connections
  //
  size_t InEventPortDelegate_Impl::in_EventSinkDelegate_connections (std::vector <EventSinkDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

