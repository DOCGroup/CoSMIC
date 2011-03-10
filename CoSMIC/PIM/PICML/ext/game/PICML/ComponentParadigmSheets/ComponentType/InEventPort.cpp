// $Id$

#include "stdafx.h"
#include "InEventPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPort_Impl::metaname = "InEventPort";

  //
  // InEventPort_Impl
  //
  InEventPort_Impl::InEventPort_Impl (void)
  {
  }

  //
  // InEventPort_Impl
  //
  InEventPort_Impl::InEventPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InEventPort_Impl
  //
  InEventPort_Impl::~InEventPort_Impl (void)
  {
  }

  //
  // accept
  //
  void InEventPort_Impl::accept (Visitor * v)
  {
    v->visit_InEventPort (this);
  }

  //
  // refers_to_EventType
  //
  EventType InEventPort_Impl::refers_to_EventType (void) const
  {
    return ::GAME::Mga::get_refers_to <EventType> (this);
  }
}

