// $Id$

#include "stdafx.h"
#include "ConnectorImplements.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplements_Impl::metaname = "ConnectorImplements";

  //
  // ConnectorImplements_Impl
  //
  ConnectorImplements_Impl::ConnectorImplements_Impl (void)
  {
  }

  //
  // ConnectorImplements_Impl
  //
  ConnectorImplements_Impl::ConnectorImplements_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorImplements_Impl
  //
  ConnectorImplements_Impl::~ConnectorImplements_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorImplements_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorImplements (this);
  }

  //
  // _create
  //
  ConnectorImplements ConnectorImplements_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ConnectorImplements> (parent, ConnectorImplements_Impl::metaname);
  }

  //
  // src_ConnectorImplementation
  //
  ConnectorImplementation ConnectorImplements_Impl::src_ConnectorImplementation (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ConnectorImplementation::_narrow (target);
  }

  //
  // dst_ConnectorType
  //
  ConnectorType ConnectorImplements_Impl::dst_ConnectorType (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ConnectorType::_narrow (target);
  }

  //
  // parent_ConnectorImplementationContainer
  //
  ConnectorImplementationContainer ConnectorImplements_Impl::parent_ConnectorImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ConnectorImplementationContainer> (this->object_.p);
  }
}

