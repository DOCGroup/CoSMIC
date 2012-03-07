// $Id$

#include "StdAfx.h"
#include "EventSourceDelegate.h"

#if !defined (__GAME_INLINE__)
#include "EventSourceDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EventSourceDelegate_Impl::metaname ("EventSourceDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  EventSourceDelegate EventSourceDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < EventSourceDelegate > (parent, EventSourceDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void EventSourceDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_EventSourceDelegate (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // OutEventPortEnd
  //
  OutEventPortEnd EventSourceDelegate_Impl::src_OutEventPortEnd (void) const
  {
    return OutEventPortEnd::_narrow (this->src ());
  }

  //
  // OutEventPortDelegate
  //
  OutEventPortDelegate EventSourceDelegate_Impl::dst_OutEventPortDelegate (void) const
  {
    return OutEventPortDelegate::_narrow (this->dst ());
  }
}

