// $Id$

#include "stdafx.h"
#include "ConnectorObject.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorInherits.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorInherits.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorObject_Impl::metaname = "ConnectorObject";

  //
  // ConnectorObject_Impl
  //
  ConnectorObject_Impl::ConnectorObject_Impl (void)
  {
  }

  //
  // ConnectorObject_Impl
  //
  ConnectorObject_Impl::ConnectorObject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorObject_Impl
  //
  ConnectorObject_Impl::~ConnectorObject_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorObject_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorObject (this);
  }

  //
  // get_ConnectorInherits
  //
  ConnectorInherits ConnectorObject_Impl::get_ConnectorInherits (void) const
  {
    // Get the collection of children.
    std::vector <ConnectorInherits> items;
    this->children (items);

    return !items.empty () ? items.front () : ConnectorInherits ();
  }

  //
  // get_Collections
  //
  size_t ConnectorObject_Impl::get_Collections (std::vector <Collection> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aggregates
  //
  size_t ConnectorObject_Impl::get_Aggregates (std::vector <Aggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPortBases
  //
  size_t ConnectorObject_Impl::get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReadonlyAttributes
  //
  size_t ConnectorObject_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_ObjectPorts
  //
  size_t ConnectorObject_Impl::get_ObjectPorts (std::vector <ObjectPort> & items) const
  {
    return this->children (items);
  }
}

