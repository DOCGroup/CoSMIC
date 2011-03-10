// $Id$

#include "stdafx.h"
#include "EventType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EventType_Impl::metaname = "EventType";

  //
  // EventType_Impl
  //
  EventType_Impl::EventType_Impl (void)
  {
  }

  //
  // EventType_Impl
  //
  EventType_Impl::EventType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventType_Impl
  //
  EventType_Impl::~EventType_Impl (void)
  {
  }
}

