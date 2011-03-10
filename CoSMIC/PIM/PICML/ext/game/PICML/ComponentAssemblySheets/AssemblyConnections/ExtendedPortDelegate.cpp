// $Id$

#include "stdafx.h"
#include "ExtendedPortDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortDelegate_Impl::metaname = "ExtendedPortDelegate";

  //
  // ExtendedPortDelegate_Impl
  //
  ExtendedPortDelegate_Impl::ExtendedPortDelegate_Impl (void)
  {
  }

  //
  // ExtendedPortDelegate_Impl
  //
  ExtendedPortDelegate_Impl::ExtendedPortDelegate_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendedPortDelegate_Impl
  //
  ExtendedPortDelegate_Impl::~ExtendedPortDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void ExtendedPortDelegate_Impl::accept (Visitor * v)
  {
    v->visit_ExtendedPortDelegate (this);
  }

  //
  // in_ExtendedDelegate_connections
  //
  size_t ExtendedPortDelegate_Impl::in_ExtendedDelegate_connections (std::vector <ExtendedDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

