// $Id$

#include "stdafx.h"
#include "Publish.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Publish_Impl::metaname = "Publish";

  //
  // Publish_Impl
  //
  Publish_Impl::Publish_Impl (void)
  {
  }

  //
  // Publish_Impl
  //
  Publish_Impl::Publish_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Publish_Impl
  //
  Publish_Impl::~Publish_Impl (void)
  {
  }

  //
  // accept
  //
  void Publish_Impl::accept (Visitor * v)
  {
    v->visit_Publish (this);
  }

  //
  // src_ExtendPortEnd
  //
  ExtendPortEnd Publish_Impl::src_ExtendPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ExtendPortEnd::_narrow (target);
  }

  //
  // dst_ConnectorInstance
  //
  ConnectorInstance Publish_Impl::dst_ConnectorInstance (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ConnectorInstance::_narrow (target);
  }
}

