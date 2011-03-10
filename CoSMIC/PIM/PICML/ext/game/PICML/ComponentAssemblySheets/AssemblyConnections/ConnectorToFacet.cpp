// $Id$

#include "stdafx.h"
#include "ConnectorToFacet.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorToFacet_Impl::metaname = "ConnectorToFacet";

  //
  // ConnectorToFacet_Impl
  //
  ConnectorToFacet_Impl::ConnectorToFacet_Impl (void)
  {
  }

  //
  // ConnectorToFacet_Impl
  //
  ConnectorToFacet_Impl::ConnectorToFacet_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorToFacet_Impl
  //
  ConnectorToFacet_Impl::~ConnectorToFacet_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorToFacet_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorToFacet (this);
  }

  //
  // src_ConnectorInstance
  //
  ConnectorInstance ConnectorToFacet_Impl::src_ConnectorInstance (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ConnectorInstance::_narrow (target);
  }

  //
  // dst_ProvidedRequestPortEnd
  //
  ProvidedRequestPortEnd ConnectorToFacet_Impl::dst_ProvidedRequestPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ProvidedRequestPortEnd::_narrow (target);
  }

  //
  // InnerName
  //
  void ConnectorToFacet_Impl::InnerName (const std::string & val)
  {
    static const std::string attr_InnerName ("InnerName");
    this->attribute (attr_InnerName)->string_value (val);
  }

  //
  // InnerName
  //
  std::string ConnectorToFacet_Impl::InnerName (void) const
  {
    static const std::string attr_InnerName ("InnerName");
    return this->attribute (attr_InnerName)->string_value ();
  }
}

