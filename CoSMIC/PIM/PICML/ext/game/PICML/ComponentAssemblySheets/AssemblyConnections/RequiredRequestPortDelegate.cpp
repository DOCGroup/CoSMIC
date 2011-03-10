// $Id$

#include "stdafx.h"
#include "RequiredRequestPortDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortDelegate_Impl::metaname = "RequiredRequestPortDelegate";

  //
  // RequiredRequestPortDelegate_Impl
  //
  RequiredRequestPortDelegate_Impl::RequiredRequestPortDelegate_Impl (void)
  {
  }

  //
  // RequiredRequestPortDelegate_Impl
  //
  RequiredRequestPortDelegate_Impl::RequiredRequestPortDelegate_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequiredRequestPortDelegate_Impl
  //
  RequiredRequestPortDelegate_Impl::~RequiredRequestPortDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void RequiredRequestPortDelegate_Impl::accept (Visitor * v)
  {
    v->visit_RequiredRequestPortDelegate (this);
  }

  //
  // in_ReceptacleDelegate_connections
  //
  size_t RequiredRequestPortDelegate_Impl::in_ReceptacleDelegate_connections (std::vector <ReceptacleDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

