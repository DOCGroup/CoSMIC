// $Id$

#include "StdAfx.h"
#include "EventSinkDelegate.h"

#if !defined (__GAME_INLINE__)
#include "EventSinkDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/InEventPortInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EventSinkDelegate_Impl::metaname ("EventSinkDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  EventSinkDelegate EventSinkDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < EventSinkDelegate > (parent, EventSinkDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void EventSinkDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_EventSinkDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly EventSinkDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // InEventPortDelegate
  //
  InEventPortDelegate EventSinkDelegate_Impl::src_InEventPortDelegate (void) const
  {
    return InEventPortDelegate::_narrow (this->src ());
  }

  //
  // InEventPortEnd
  //
  InEventPortEnd EventSinkDelegate_Impl::dst_InEventPortEnd (void) const
  {
    return InEventPortEnd::_narrow (this->dst ());
  }
}

