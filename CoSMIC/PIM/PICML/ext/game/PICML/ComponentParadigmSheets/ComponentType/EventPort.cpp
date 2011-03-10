// $Id$

#include "stdafx.h"
#include "EventPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EventPort_Impl::metaname = "EventPort";

  //
  // EventPort_Impl
  //
  EventPort_Impl::EventPort_Impl (void)
  {
  }

  //
  // EventPort_Impl
  //
  EventPort_Impl::EventPort_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventPort_Impl
  //
  EventPort_Impl::~EventPort_Impl (void)
  {
  }
}

