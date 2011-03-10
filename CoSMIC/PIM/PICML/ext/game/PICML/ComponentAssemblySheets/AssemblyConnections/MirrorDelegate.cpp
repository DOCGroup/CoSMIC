// $Id$

#include "stdafx.h"
#include "MirrorDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortInstanceBase.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorDelegate_Impl::metaname = "MirrorDelegate";

  //
  // MirrorDelegate_Impl
  //
  MirrorDelegate_Impl::MirrorDelegate_Impl (void)
  {
  }

  //
  // MirrorDelegate_Impl
  //
  MirrorDelegate_Impl::MirrorDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MirrorDelegate_Impl
  //
  MirrorDelegate_Impl::~MirrorDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void MirrorDelegate_Impl::accept (Visitor * v)
  {
    v->visit_MirrorDelegate (this);
  }

  //
  // src_MirrorPortInstanceBase
  //
  MirrorPortInstanceBase MirrorDelegate_Impl::src_MirrorPortInstanceBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return MirrorPortInstanceBase::_narrow (target);
  }

  //
  // dst_MirrorPortDelegate
  //
  MirrorPortDelegate MirrorDelegate_Impl::dst_MirrorPortDelegate (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return MirrorPortDelegate::_narrow (target);
  }
}

