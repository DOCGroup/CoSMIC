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
  // is_abstract
  //
  const bool ExtendedPortBase_Impl::is_abstract = true;

  //
  // parent_ConnectorObject
  //
  ConnectorObject ExtendedPortBase_Impl::parent_ConnectorObject (void)
  {
    return ConnectorObject::_narrow (this->parent ());
  }

  //
  // parent_Component
  //
  Component ExtendedPortBase_Impl::parent_Component (void)
  {
    return Component::_narrow (this->parent ());
  }

  //
  // PortType_is_nil
  //
  bool ExtendedPortBase_Impl::PortType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_PortType
  //
  void ExtendedPortBase_Impl::refers_to_PortType (PortType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_PortType
  //
  PortType ExtendedPortBase_Impl::refers_to_PortType (void) const
  {
    return PortType::_narrow (this->refers_to ());
  }
}

