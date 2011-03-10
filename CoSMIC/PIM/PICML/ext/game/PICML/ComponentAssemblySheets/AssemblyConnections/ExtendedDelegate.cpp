// $Id$

#include "stdafx.h"
#include "ExtendedDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortInstanceBase.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedDelegate_Impl::metaname = "ExtendedDelegate";

  //
  // ExtendedDelegate_Impl
  //
  ExtendedDelegate_Impl::ExtendedDelegate_Impl (void)
  {
  }

  //
  // ExtendedDelegate_Impl
  //
  ExtendedDelegate_Impl::ExtendedDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendedDelegate_Impl
  //
  ExtendedDelegate_Impl::~ExtendedDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void ExtendedDelegate_Impl::accept (Visitor * v)
  {
    v->visit_ExtendedDelegate (this);
  }

  //
  // src_ExtendedPortInstanceBase
  //
  ExtendedPortInstanceBase ExtendedDelegate_Impl::src_ExtendedPortInstanceBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ExtendedPortInstanceBase::_narrow (target);
  }

  //
  // dst_ExtendedPortDelegate
  //
  ExtendedPortDelegate ExtendedDelegate_Impl::dst_ExtendedPortDelegate (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ExtendedPortDelegate::_narrow (target);
  }
}

