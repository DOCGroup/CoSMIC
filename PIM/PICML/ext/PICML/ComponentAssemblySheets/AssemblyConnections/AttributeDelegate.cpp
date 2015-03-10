// $Id$

#include "StdAfx.h"
#include "AttributeDelegate.h"

#if !defined (__GAME_INLINE__)
#include "AttributeDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeDelegate_Impl::metaname ("AttributeDelegate");

  //
  // is_abstract
  //
  const bool AttributeDelegate_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, AttributeMapping_in src, AttributeInstance_in dst)
  //
  AttributeDelegate AttributeDelegate_Impl::_create (const ComponentAssembly_in parent, AttributeMapping_in src, AttributeInstance_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, AttributeDelegate_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void AttributeDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AttributeDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // AttributeMapping
  //
  AttributeMapping AttributeDelegate_Impl::src_AttributeMapping (void) const
  {
    return AttributeMapping::_narrow (this->src ());
  }

  //
  // AttributeInstance
  //
  AttributeInstance AttributeDelegate_Impl::dst_AttributeInstance (void) const
  {
    return AttributeInstance::_narrow (this->dst ());
  }
}

