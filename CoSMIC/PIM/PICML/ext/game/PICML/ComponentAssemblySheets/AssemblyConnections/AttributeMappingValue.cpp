// $Id$

#include "stdafx.h"
#include "AttributeMappingValue.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMappingValue_Impl::metaname = "AttributeMappingValue";

  //
  // AttributeMappingValue_Impl
  //
  AttributeMappingValue_Impl::AttributeMappingValue_Impl (void)
  {
  }

  //
  // AttributeMappingValue_Impl
  //
  AttributeMappingValue_Impl::AttributeMappingValue_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeMappingValue_Impl
  //
  AttributeMappingValue_Impl::~AttributeMappingValue_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeMappingValue_Impl::accept (Visitor * v)
  {
    v->visit_AttributeMappingValue (this);
  }

  //
  // src_AttributeMapping
  //
  AttributeMapping AttributeMappingValue_Impl::src_AttributeMapping (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return AttributeMapping::_narrow (target);
  }

  //
  // dst_Property
  //
  Property AttributeMappingValue_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }
}

