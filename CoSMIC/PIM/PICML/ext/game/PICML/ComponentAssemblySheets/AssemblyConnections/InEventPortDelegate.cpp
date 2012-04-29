// $Id$

#include "StdAfx.h"
#include "InEventPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "InEventPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortDelegate_Impl::metaname ("InEventPortDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  InEventPortDelegate InEventPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < InEventPortDelegate > (parent, InEventPortDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void InEventPortDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InEventPortDelegate (this);
    else
      v->visit_Atom (this);
  }

  //
  // src_EventSinkDelegate
  //
  size_t InEventPortDelegate_Impl::src_EventSinkDelegate (std::vector <EventSinkDelegate> & items) const
  {
    return this->in_connections <EventSinkDelegate> (items);
  }
}

