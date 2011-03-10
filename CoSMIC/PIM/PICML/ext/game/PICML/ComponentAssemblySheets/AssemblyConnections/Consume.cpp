// $Id$

#include "stdafx.h"
#include "Consume.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Consume_Impl::metaname = "Consume";

  //
  // Consume_Impl
  //
  Consume_Impl::Consume_Impl (void)
  {
  }

  //
  // Consume_Impl
  //
  Consume_Impl::Consume_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Consume_Impl
  //
  Consume_Impl::~Consume_Impl (void)
  {
  }

  //
  // accept
  //
  void Consume_Impl::accept (Visitor * v)
  {
    v->visit_Consume (this);
  }

  //
  // src_ConnectorInstance
  //
  ConnectorInstance Consume_Impl::src_ConnectorInstance (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ConnectorInstance::_narrow (target);
  }

  //
  // dst_ExtendPortEnd
  //
  ExtendPortEnd Consume_Impl::dst_ExtendPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ExtendPortEnd::_narrow (target);
  }
}

