// $Id$

#include "stdafx.h"
#include "ComponentFactory.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ManagesComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/LookupKey.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactory_Impl::metaname = "ComponentFactory";

  //
  // ComponentFactory_Impl
  //
  ComponentFactory_Impl::ComponentFactory_Impl (void)
  {
  }

  //
  // ComponentFactory_Impl
  //
  ComponentFactory_Impl::ComponentFactory_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactory_Impl
  //
  ComponentFactory_Impl::~ComponentFactory_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentFactory_Impl::accept (Visitor * v)
  {
    v->visit_ComponentFactory (this);
  }

  //
  // in_ManagesComponent_connections
  //
  size_t ComponentFactory_Impl::in_ManagesComponent_connections (std::vector <ManagesComponent> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // get_LookupKey
  //
  LookupKey ComponentFactory_Impl::get_LookupKey (void) const
  {
    // Get the collection of children.
    std::vector <LookupKey> items;
    this->children (items);

    return !items.empty () ? items.front () : LookupKey ();
  }
}

