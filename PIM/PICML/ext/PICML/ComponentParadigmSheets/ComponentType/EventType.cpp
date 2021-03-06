#include "StdAfx.h"
#include "EventType.h"

#if !defined (__GAME_INLINE__)
#include "EventType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EventType_Impl::metaname ("EventType");

  //
  // is_abstract
  //
  const bool EventType_Impl::is_abstract = true;
}

