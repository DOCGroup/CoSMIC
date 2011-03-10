// $Id$

#include "stdafx.h"
#include "MirrorPortDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortDelegate_Impl::metaname = "MirrorPortDelegate";

  //
  // MirrorPortDelegate_Impl
  //
  MirrorPortDelegate_Impl::MirrorPortDelegate_Impl (void)
  {
  }

  //
  // MirrorPortDelegate_Impl
  //
  MirrorPortDelegate_Impl::MirrorPortDelegate_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MirrorPortDelegate_Impl
  //
  MirrorPortDelegate_Impl::~MirrorPortDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void MirrorPortDelegate_Impl::accept (Visitor * v)
  {
    v->visit_MirrorPortDelegate (this);
  }

  //
  // in_MirrorDelegate_connections
  //
  size_t MirrorPortDelegate_Impl::in_MirrorDelegate_connections (std::vector <MirrorDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

