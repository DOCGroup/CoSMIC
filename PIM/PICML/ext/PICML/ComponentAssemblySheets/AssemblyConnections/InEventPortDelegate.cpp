#include "StdAfx.h"
#include "InEventPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "InEventPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/EventSinkDelegate.h"
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
  // is_abstract
  //
  const bool InEventPortDelegate_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  InEventPortDelegate InEventPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < InEventPortDelegate > (parent, InEventPortDelegate_Impl::metaname);
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
  // parent_ComponentAssembly
  //
  ComponentAssembly InEventPortDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // src_of_EventSinkDelegate
  //
  size_t InEventPortDelegate_Impl::src_of_EventSinkDelegate (std::vector <EventSinkDelegate> & items) const
  {
    return this->in_connections <EventSinkDelegate> (items);
  }

  //
  // src_of_EventSinkDelegate
  //
  GAME::Mga::Collection_T <EventSinkDelegate> InEventPortDelegate_Impl::src_of_EventSinkDelegate (void) const
  {
    return this->in_connections <EventSinkDelegate> ("src");
  }
}

