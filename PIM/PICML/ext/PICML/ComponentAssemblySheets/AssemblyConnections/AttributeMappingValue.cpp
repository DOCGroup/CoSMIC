// $Id$

#include "StdAfx.h"
#include "AttributeMappingValue.h"

#if !defined (__GAME_INLINE__)
#include "AttributeMappingValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
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
  const std::string AttributeMappingValue_Impl::metaname ("AttributeMappingValue");

  //
  // is_abstract
  //
  const bool AttributeMappingValue_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, AttributeMapping_in src, Property_in dst)
  //
  AttributeMappingValue AttributeMappingValue_Impl::_create (const ComponentAssembly_in parent, AttributeMapping_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, AttributeMappingValue_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void AttributeMappingValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeMappingValue (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AttributeMappingValue_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // AttributeMapping
  //
  AttributeMapping AttributeMappingValue_Impl::src_AttributeMapping (void) const
  {
    return AttributeMapping::_narrow (this->src ());
  }

  //
  // Property
  //
  Property AttributeMappingValue_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

