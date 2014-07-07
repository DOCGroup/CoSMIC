// $Id$

#include "StdAfx.h"
#include "ExtendedDelegate.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortInstanceBase.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ExtendedPortInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedDelegate_Impl::metaname ("ExtendedDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  ExtendedDelegate ExtendedDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ExtendedDelegate > (parent, ExtendedDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void ExtendedDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExtendedDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ExtendedDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // ExtendedPortInstanceBase
  //
  ExtendedPortInstanceBase ExtendedDelegate_Impl::src_ExtendedPortInstanceBase (void) const
  {
    return ExtendedPortInstanceBase::_narrow (this->src ());
  }

  //
  // ExtendedPortDelegate
  //
  ExtendedPortDelegate ExtendedDelegate_Impl::dst_ExtendedPortDelegate (void) const
  {
    return ExtendedPortDelegate::_narrow (this->dst ());
  }
}

