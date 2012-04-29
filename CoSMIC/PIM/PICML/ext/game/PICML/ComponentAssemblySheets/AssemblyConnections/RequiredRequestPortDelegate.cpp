// $Id$

#include "StdAfx.h"
#include "RequiredRequestPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "RequiredRequestPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ReceptacleDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortDelegate_Impl::metaname ("RequiredRequestPortDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  RequiredRequestPortDelegate RequiredRequestPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < RequiredRequestPortDelegate > (parent, RequiredRequestPortDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void RequiredRequestPortDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RequiredRequestPortDelegate (this);
    else
      v->visit_Atom (this);
  }

  //
  // src_ReceptacleDelegate
  //
  size_t RequiredRequestPortDelegate_Impl::src_ReceptacleDelegate (std::vector <ReceptacleDelegate> & items) const
  {
    return this->in_connections <ReceptacleDelegate> (items);
  }
}

