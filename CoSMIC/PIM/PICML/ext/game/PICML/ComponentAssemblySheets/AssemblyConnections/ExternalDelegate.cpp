// $Id$

#include "stdafx.h"
#include "ExternalDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ExternalPort.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalDelegate_Impl::metaname = "ExternalDelegate";

  //
  // ExternalDelegate_Impl
  //
  ExternalDelegate_Impl::ExternalDelegate_Impl (void)
  {
  }

  //
  // ExternalDelegate_Impl
  //
  ExternalDelegate_Impl::ExternalDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExternalDelegate_Impl
  //
  ExternalDelegate_Impl::~ExternalDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void ExternalDelegate_Impl::accept (Visitor * v)
  {
    v->visit_ExternalDelegate (this);
  }

  //
  // src_ExternalPort
  //
  ExternalPort ExternalDelegate_Impl::src_ExternalPort (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ExternalPort::_narrow (target);
  }

  //
  // dst_ExternalPortEnd
  //
  ExternalPortEnd ExternalDelegate_Impl::dst_ExternalPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ExternalPortEnd::_narrow (target);
  }
}

