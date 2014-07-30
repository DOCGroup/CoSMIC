// $Id$

#include "StdAfx.h"
#include "MirrorDelegate.h"

#if !defined (__GAME_INLINE__)
#include "MirrorDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortInstanceBase.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/MirrorPortInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorDelegate_Impl::metaname ("MirrorDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  MirrorDelegate MirrorDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < MirrorDelegate > (parent, MirrorDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void MirrorDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MirrorDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly MirrorDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // MirrorPortInstanceBase
  //
  MirrorPortInstanceBase MirrorDelegate_Impl::src_MirrorPortInstanceBase (void) const
  {
    return MirrorPortInstanceBase::_narrow (this->src ());
  }

  //
  // MirrorPortDelegate
  //
  MirrorPortDelegate MirrorDelegate_Impl::dst_MirrorPortDelegate (void) const
  {
    return MirrorPortDelegate::_narrow (this->dst ());
  }
}
