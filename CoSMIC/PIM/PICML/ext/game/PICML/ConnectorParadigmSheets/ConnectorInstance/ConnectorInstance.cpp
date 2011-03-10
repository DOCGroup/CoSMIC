// $Id$

#include "stdafx.h"
#include "ConnectorInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorImplementationType.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorInstance_Impl::metaname = "ConnectorInstance";

  //
  // ConnectorInstance_Impl
  //
  ConnectorInstance_Impl::ConnectorInstance_Impl (void)
  {
  }

  //
  // ConnectorInstance_Impl
  //
  ConnectorInstance_Impl::ConnectorInstance_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorInstance_Impl
  //
  ConnectorInstance_Impl::~ConnectorInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorInstance_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorInstance (this);
  }

  //
  // get_ConnectorImplementationType
  //
  ConnectorImplementationType ConnectorInstance_Impl::get_ConnectorImplementationType (void) const
  {
    // Get the collection of children.
    std::vector <ConnectorImplementationType> items;
    this->children (items);

    return !items.empty () ? items.front () : ConnectorImplementationType ();
  }

  //
  // get_AttributeInstances
  //
  size_t ConnectorInstance_Impl::get_AttributeInstances (std::vector <AttributeInstance> & items) const
  {
    return this->children (items);
  }
}

