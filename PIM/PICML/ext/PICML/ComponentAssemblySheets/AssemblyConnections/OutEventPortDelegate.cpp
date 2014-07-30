// $Id$

#include "StdAfx.h"
#include "OutEventPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "OutEventPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSourceDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortDelegate_Impl::metaname ("OutEventPortDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  OutEventPortDelegate OutEventPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < OutEventPortDelegate > (parent, OutEventPortDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void OutEventPortDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OutEventPortDelegate (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly OutEventPortDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // dst_EventSourceDelegate
  //
  size_t OutEventPortDelegate_Impl::dst_EventSourceDelegate (std::vector <EventSourceDelegate> & items) const
  {
    return this->in_connections <EventSourceDelegate> (items);
  }
}
