// $Id$

#include "stdafx.h"
#include "Event.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Event_Impl::metaname = "Event";

  //
  // Event_Impl
  //
  Event_Impl::Event_Impl (void)
  {
  }

  //
  // Event_Impl
  //
  Event_Impl::Event_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Event_Impl
  //
  Event_Impl::~Event_Impl (void)
  {
  }

  //
  // accept
  //
  void Event_Impl::accept (Visitor * v)
  {
    v->visit_Event (this);
  }
}

