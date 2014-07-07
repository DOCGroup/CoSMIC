// $Id$

#include "StdAfx.h"
#include "ReceptacleDelegate.h"

#if !defined (__GAME_INLINE__)
#include "ReceptacleDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/RequiredRequestPortInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ReceptacleDelegate_Impl::metaname ("ReceptacleDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  ReceptacleDelegate ReceptacleDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ReceptacleDelegate > (parent, ReceptacleDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void ReceptacleDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ReceptacleDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ReceptacleDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // RequiredRequestPortDelegate
  //
  RequiredRequestPortDelegate ReceptacleDelegate_Impl::src_RequiredRequestPortDelegate (void) const
  {
    return RequiredRequestPortDelegate::_narrow (this->src ());
  }

  //
  // RequiredRequestPortEnd
  //
  RequiredRequestPortEnd ReceptacleDelegate_Impl::dst_RequiredRequestPortEnd (void) const
  {
    return RequiredRequestPortEnd::_narrow (this->dst ());
  }
}

