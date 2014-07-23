// $Id$

#include "StdAfx.h"
#include "ObjectPort.h"

#if !defined (__GAME_INLINE__)
#include "ObjectPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/PathDiagram/Path.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ObjectPort_Impl::metaname ("ObjectPort");

  //
  // parent_ConnectorObject
  //
  ConnectorObject ObjectPort_Impl::parent_ConnectorObject (void)
  {
    return ConnectorObject::_narrow (this->parent ());
  }

  //
  // parent_PortType
  //
  PortType ObjectPort_Impl::parent_PortType (void)
  {
    return PortType::_narrow (this->parent ());
  }
}

