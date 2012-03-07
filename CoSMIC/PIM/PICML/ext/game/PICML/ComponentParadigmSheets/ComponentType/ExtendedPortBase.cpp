// $Id$

#include "StdAfx.h"
#include "ExtendedPortBase.h"

#if !defined (__GAME_INLINE__)
#include "ExtendedPortBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortBase_Impl::metaname ("ExtendedPortBase");

  //
  // PortType_is_nil
  //
  bool ExtendedPortBase_Impl::PortType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_PortType
  //
  PortType ExtendedPortBase_Impl::get_PortType (void) const
  {
    return PortType::_narrow (this->refers_to ());
  }
}

