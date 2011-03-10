// $Id$

#include "stdafx.h"
#include "ConnectorType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorType_Impl::metaname = "ConnectorType";

  //
  // ConnectorType_Impl
  //
  ConnectorType_Impl::ConnectorType_Impl (void)
  {
  }

  //
  // ConnectorType_Impl
  //
  ConnectorType_Impl::ConnectorType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorType_Impl
  //
  ConnectorType_Impl::~ConnectorType_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorType_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorType (this);
  }

  //
  // _create
  //
  ConnectorType ConnectorType_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ConnectorType> (parent, ConnectorType_Impl::metaname);
  }

  //
  // in_ConnectorImplements_connections
  //
  size_t ConnectorType_Impl::in_ConnectorImplements_connections (std::vector <ConnectorImplements> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_ConnectorImplementationContainer
  //
  ConnectorImplementationContainer ConnectorType_Impl::parent_ConnectorImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ConnectorImplementationContainer> (this->object_.p);
  }
}

