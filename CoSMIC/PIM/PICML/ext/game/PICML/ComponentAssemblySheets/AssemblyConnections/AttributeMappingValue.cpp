// $Id$

#include "StdAfx.h"
#include "AttributeMappingValue.h"

#if !defined (__GAME_INLINE__)
#include "AttributeMappingValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/Common/Property.h"
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
  // _create (const ComponentAssembly_in)
  //
  AttributeMappingValue AttributeMappingValue_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < AttributeMappingValue > (parent, AttributeMappingValue_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeMappingValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_AttributeMappingValue (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

