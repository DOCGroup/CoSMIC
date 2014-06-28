// $Id$

#include "StdAfx.h"
#include "Port.h"

#if !defined (__GAME_INLINE__)
#include "Port.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/PathDiagram/Path.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Port_Impl::metaname ("Port");

  //
  // parent_Component
  //
  Component Port_Impl::parent_Component (void)
  {
    return Component::_narrow (this->parent ());
  }

  //
  // parent_ConnectedComponent
  //
  ConnectedComponent Port_Impl::parent_ConnectedComponent (void)
  {
    return ConnectedComponent::_narrow (this->parent ());
  }
}

