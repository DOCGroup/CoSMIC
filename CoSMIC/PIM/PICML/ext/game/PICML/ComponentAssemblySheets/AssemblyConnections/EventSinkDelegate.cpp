// $Id$

#include "stdafx.h"
#include "EventSinkDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EventSinkDelegate_Impl::metaname = "EventSinkDelegate";

  //
  // EventSinkDelegate_Impl
  //
  EventSinkDelegate_Impl::EventSinkDelegate_Impl (void)
  {
  }

  //
  // EventSinkDelegate_Impl
  //
  EventSinkDelegate_Impl::EventSinkDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventSinkDelegate_Impl
  //
  EventSinkDelegate_Impl::~EventSinkDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void EventSinkDelegate_Impl::accept (Visitor * v)
  {
    v->visit_EventSinkDelegate (this);
  }

  //
  // src_InEventPortDelegate
  //
  InEventPortDelegate EventSinkDelegate_Impl::src_InEventPortDelegate (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return InEventPortDelegate::_narrow (target);
  }

  //
  // dst_InEventPortEnd
  //
  InEventPortEnd EventSinkDelegate_Impl::dst_InEventPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return InEventPortEnd::_narrow (target);
  }
}

