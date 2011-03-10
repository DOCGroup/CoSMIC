// $Id$

#include "stdafx.h"
#include "ProvidedRequestPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPort_Impl::metaname = "ProvidedRequestPort";

  //
  // ProvidedRequestPort_Impl
  //
  ProvidedRequestPort_Impl::ProvidedRequestPort_Impl (void)
  {
  }

  //
  // ProvidedRequestPort_Impl
  //
  ProvidedRequestPort_Impl::ProvidedRequestPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ProvidedRequestPort_Impl
  //
  ProvidedRequestPort_Impl::~ProvidedRequestPort_Impl (void)
  {
  }

  //
  // accept
  //
  void ProvidedRequestPort_Impl::accept (Visitor * v)
  {
    v->visit_ProvidedRequestPort (this);
  }

  //
  // refers_to_Provideable
  //
  Provideable ProvidedRequestPort_Impl::refers_to_Provideable (void) const
  {
    return ::GAME::Mga::get_refers_to <Provideable> (this);
  }
}

