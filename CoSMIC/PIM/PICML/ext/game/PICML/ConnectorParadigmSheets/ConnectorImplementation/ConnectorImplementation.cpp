// $Id$

#include "stdafx.h"
#include "ConnectorImplementation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementation_Impl::metaname = "ConnectorImplementation";

  //
  // ConnectorImplementation_Impl
  //
  ConnectorImplementation_Impl::ConnectorImplementation_Impl (void)
  {
  }

  //
  // ConnectorImplementation_Impl
  //
  ConnectorImplementation_Impl::ConnectorImplementation_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorImplementation_Impl
  //
  ConnectorImplementation_Impl::~ConnectorImplementation_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorImplementation_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorImplementation (this);
  }

  //
  // _create
  //
  ConnectorImplementation ConnectorImplementation_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ConnectorImplementation> (parent, ConnectorImplementation_Impl::metaname);
  }

  //
  // in_ConnectorImplements_connections
  //
  size_t ConnectorImplementation_Impl::in_ConnectorImplements_connections (std::vector <ConnectorImplements> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_ConnectorImplementationContainer
  //
  ConnectorImplementationContainer ConnectorImplementation_Impl::parent_ConnectorImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ConnectorImplementationContainer> (this->object_.p);
  }
}

