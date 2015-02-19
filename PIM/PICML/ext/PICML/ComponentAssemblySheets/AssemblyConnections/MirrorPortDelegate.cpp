// $Id$

#include "StdAfx.h"
#include "MirrorPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "MirrorPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/MirrorDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortDelegate_Impl::metaname ("MirrorPortDelegate");

  //
  // is_abstract
  //
  const bool MirrorPortDelegate_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  MirrorPortDelegate MirrorPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < MirrorPortDelegate > (parent, MirrorPortDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void MirrorPortDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MirrorPortDelegate (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly MirrorPortDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // dst_of_MirrorDelegate
  //
  size_t MirrorPortDelegate_Impl::dst_of_MirrorDelegate (std::vector <MirrorDelegate> & items) const
  {
    return this->in_connections <MirrorDelegate> (items);
  }

  //
  // has_dst_of_MirrorDelegate
  //
  bool MirrorPortDelegate_Impl::has_dst_of_MirrorDelegate (void) const
  {
    return this->in_connections <MirrorDelegate> ("dst").count () == 1;
  }

  //
  // dst_of_MirrorDelegate
  //
  MirrorDelegate MirrorPortDelegate_Impl::dst_of_MirrorDelegate (void) const
  {
    return this->in_connections <MirrorDelegate> ("dst").first ();
  }
}

