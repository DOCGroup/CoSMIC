// $Id$

#include "stdafx.h"
#include "AttributeMapping.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMappingValue.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMapping_Impl::metaname = "AttributeMapping";

  //
  // AttributeMapping_Impl
  //
  AttributeMapping_Impl::AttributeMapping_Impl (void)
  {
  }

  //
  // AttributeMapping_Impl
  //
  AttributeMapping_Impl::AttributeMapping_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeMapping_Impl
  //
  AttributeMapping_Impl::~AttributeMapping_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeMapping_Impl::accept (Visitor * v)
  {
    v->visit_AttributeMapping (this);
  }

  //
  // in_AttributeDelegate_connections
  //
  size_t AttributeMapping_Impl::in_AttributeDelegate_connections (std::vector <AttributeDelegate> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_AttributeMappingDelegate_connections
  //
  size_t AttributeMapping_Impl::in_AttributeMappingDelegate_connections (std::vector <AttributeMappingDelegate> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_AttributeMappingValue_connections
  //
  size_t AttributeMapping_Impl::in_AttributeMappingValue_connections (std::vector <AttributeMappingValue> & conns) const
  {
    return this->in_connections (conns);
  }
}

