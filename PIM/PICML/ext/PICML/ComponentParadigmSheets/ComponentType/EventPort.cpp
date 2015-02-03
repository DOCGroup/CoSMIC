// $Id$

#include "StdAfx.h"
#include "EventPort.h"

#if !defined (__GAME_INLINE__)
#include "EventPort.inl"
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
  const std::string EventPort_Impl::metaname ("EventPort");

  //
  // is_abstract
  //
  const bool EventPort_Impl::is_abstract (1);
}

