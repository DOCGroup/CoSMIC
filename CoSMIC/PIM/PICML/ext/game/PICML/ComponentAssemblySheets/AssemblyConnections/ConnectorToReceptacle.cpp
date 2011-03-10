// $Id$

#include "stdafx.h"
#include "ConnectorToReceptacle.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorToReceptacle_Impl::metaname = "ConnectorToReceptacle";

  //
  // ConnectorToReceptacle_Impl
  //
  ConnectorToReceptacle_Impl::ConnectorToReceptacle_Impl (void)
  {
  }

  //
  // ConnectorToReceptacle_Impl
  //
  ConnectorToReceptacle_Impl::ConnectorToReceptacle_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorToReceptacle_Impl
  //
  ConnectorToReceptacle_Impl::~ConnectorToReceptacle_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorToReceptacle_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorToReceptacle (this);
  }

  //
  // src_RequiredRequestPortEnd
  //
  RequiredRequestPortEnd ConnectorToReceptacle_Impl::src_RequiredRequestPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return RequiredRequestPortEnd::_narrow (target);
  }

  //
  // dst_ConnectorInstance
  //
  ConnectorInstance ConnectorToReceptacle_Impl::dst_ConnectorInstance (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ConnectorInstance::_narrow (target);
  }

  //
  // InnerName
  //
  void ConnectorToReceptacle_Impl::InnerName (const std::string & val)
  {
    static const std::string attr_InnerName ("InnerName");
    this->attribute (attr_InnerName)->string_value (val);
  }

  //
  // InnerName
  //
  std::string ConnectorToReceptacle_Impl::InnerName (void) const
  {
    static const std::string attr_InnerName ("InnerName");
    return this->attribute (attr_InnerName)->string_value ();
  }
}

