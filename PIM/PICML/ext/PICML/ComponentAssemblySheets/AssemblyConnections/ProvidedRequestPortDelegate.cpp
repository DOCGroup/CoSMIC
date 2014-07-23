// $Id$

#include "StdAfx.h"
#include "ProvidedRequestPortDelegate.h"

#if !defined (__GAME_INLINE__)
#include "ProvidedRequestPortDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortDelegate_Impl::metaname ("ProvidedRequestPortDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  ProvidedRequestPortDelegate ProvidedRequestPortDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPortDelegate > (parent, ProvidedRequestPortDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void ProvidedRequestPortDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ProvidedRequestPortDelegate (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ProvidedRequestPortDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // src_FacetDelegate
  //
  size_t ProvidedRequestPortDelegate_Impl::src_FacetDelegate (std::vector <FacetDelegate> & items) const
  {
    return this->in_connections <FacetDelegate> (items);
  }
}

