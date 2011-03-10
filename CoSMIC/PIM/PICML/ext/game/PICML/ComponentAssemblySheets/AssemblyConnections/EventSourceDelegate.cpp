// $Id$

#include "stdafx.h"
#include "EventSourceDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EventSourceDelegate_Impl::metaname = "EventSourceDelegate";

  //
  // EventSourceDelegate_Impl
  //
  EventSourceDelegate_Impl::EventSourceDelegate_Impl (void)
  {
  }

  //
  // EventSourceDelegate_Impl
  //
  EventSourceDelegate_Impl::EventSourceDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventSourceDelegate_Impl
  //
  EventSourceDelegate_Impl::~EventSourceDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void EventSourceDelegate_Impl::accept (Visitor * v)
  {
    v->visit_EventSourceDelegate (this);
  }

  //
  // src_OutEventPortEnd
  //
  OutEventPortEnd EventSourceDelegate_Impl::src_OutEventPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return OutEventPortEnd::_narrow (target);
  }

  //
  // dst_OutEventPortDelegate
  //
  OutEventPortDelegate EventSourceDelegate_Impl::dst_OutEventPortDelegate (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return OutEventPortDelegate::_narrow (target);
  }
}

