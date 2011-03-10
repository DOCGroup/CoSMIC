// $Id$

#include "stdafx.h"
#include "Component.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentInherits.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Component_Impl::metaname = "Component";

  //
  // Component_Impl
  //
  Component_Impl::Component_Impl (void)
  {
  }

  //
  // Component_Impl
  //
  Component_Impl::Component_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Component_Impl
  //
  Component_Impl::~Component_Impl (void)
  {
  }

  //
  // accept
  //
  void Component_Impl::accept (Visitor * v)
  {
    v->visit_Component (this);
  }

  //
  // get_ExtendedPortBases
  //
  size_t Component_Impl::get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentInherits
  //
  ComponentInherits Component_Impl::get_ComponentInherits (void) const
  {
    // Get the collection of children.
    std::vector <ComponentInherits> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentInherits ();
  }

  //
  // get_ReadonlyAttributes
  //
  size_t Component_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_Ports
  //
  size_t Component_Impl::get_Ports (std::vector <Port> & items) const
  {
    return this->children (items);
  }
}

