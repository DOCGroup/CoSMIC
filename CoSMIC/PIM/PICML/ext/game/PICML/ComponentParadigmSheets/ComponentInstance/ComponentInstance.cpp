// $Id$

#include "stdafx.h"
#include "ComponentInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstanceType.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstance_Impl::metaname = "ComponentInstance";

  //
  // ComponentInstance_Impl
  //
  ComponentInstance_Impl::ComponentInstance_Impl (void)
  {
  }

  //
  // ComponentInstance_Impl
  //
  ComponentInstance_Impl::ComponentInstance_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInstance_Impl
  //
  ComponentInstance_Impl::~ComponentInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentInstance_Impl::accept (Visitor * v)
  {
    v->visit_ComponentInstance (this);
  }

  //
  // get_PortInstances
  //
  size_t ComponentInstance_Impl::get_PortInstances (std::vector <PortInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentInstanceType
  //
  ComponentInstanceType ComponentInstance_Impl::get_ComponentInstanceType (void) const
  {
    // Get the collection of children.
    std::vector <ComponentInstanceType> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentInstanceType ();
  }

  //
  // get_SupportsInstances
  //
  size_t ComponentInstance_Impl::get_SupportsInstances (std::vector <SupportsInstance> & items) const
  {
    return this->children (items);
  }
}

