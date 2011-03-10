// $Id$

#include "stdafx.h"
#include "ReceptacleDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ReceptacleDelegate_Impl::metaname = "ReceptacleDelegate";

  //
  // ReceptacleDelegate_Impl
  //
  ReceptacleDelegate_Impl::ReceptacleDelegate_Impl (void)
  {
  }

  //
  // ReceptacleDelegate_Impl
  //
  ReceptacleDelegate_Impl::ReceptacleDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReceptacleDelegate_Impl
  //
  ReceptacleDelegate_Impl::~ReceptacleDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void ReceptacleDelegate_Impl::accept (Visitor * v)
  {
    v->visit_ReceptacleDelegate (this);
  }

  //
  // src_RequiredRequestPortDelegate
  //
  RequiredRequestPortDelegate ReceptacleDelegate_Impl::src_RequiredRequestPortDelegate (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return RequiredRequestPortDelegate::_narrow (target);
  }

  //
  // dst_RequiredRequestPortEnd
  //
  RequiredRequestPortEnd ReceptacleDelegate_Impl::dst_RequiredRequestPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return RequiredRequestPortEnd::_narrow (target);
  }
}

