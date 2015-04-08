#include "StdAfx.h"
#include "ExtendedPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedDelegate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortDelegate_Impl::metaname ("ExtendedPortDelegate");

  //
  // is_abstract
  //
  const bool ExtendedPortDelegate_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  ExtendedPortDelegate ExtendedPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < ExtendedPortDelegate > (parent, ExtendedPortDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void ExtendedPortDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExtendedPortDelegate (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ExtendedPortDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // dst_of_ExtendedDelegate
  //
  size_t ExtendedPortDelegate_Impl::dst_of_ExtendedDelegate (std::vector <ExtendedDelegate> & items) const
  {
    return this->in_connections <ExtendedDelegate> (items);
  }

  //
  // dst_of_ExtendedDelegate
  //
  GAME::Mga::Collection_T <ExtendedDelegate> ExtendedPortDelegate_Impl::dst_of_ExtendedDelegate (void) const
  {
    return this->in_connections <ExtendedDelegate> ("dst");
  }
}

