// $Id$

#include "StdAfx.h"
#include "AttributeMappingDelegate.h"

#if !defined (__GAME_INLINE__)
#include "AttributeMappingDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMappingDelegate_Impl::metaname ("AttributeMappingDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  AttributeMappingDelegate AttributeMappingDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < AttributeMappingDelegate > (parent, AttributeMappingDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeMappingDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeMappingDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AttributeMappingDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // AttributeMapping
  //
  AttributeMapping AttributeMappingDelegate_Impl::src_AttributeMapping (void) const
  {
    return AttributeMapping::_narrow (this->src ());
  }

  //
  // AttributeMapping
  //
  AttributeMapping AttributeMappingDelegate_Impl::dst_AttributeMapping (void) const
  {
    return AttributeMapping::_narrow (this->dst ());
  }
}

