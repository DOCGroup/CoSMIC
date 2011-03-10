// $Id$

#include "stdafx.h"
#include "ProvidedRequestPortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortInstance_Impl::metaname = "ProvidedRequestPortInstance";

  //
  // ProvidedRequestPortInstance_Impl
  //
  ProvidedRequestPortInstance_Impl::ProvidedRequestPortInstance_Impl (void)
  {
  }

  //
  // ProvidedRequestPortInstance_Impl
  //
  ProvidedRequestPortInstance_Impl::ProvidedRequestPortInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ProvidedRequestPortInstance_Impl
  //
  ProvidedRequestPortInstance_Impl::~ProvidedRequestPortInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void ProvidedRequestPortInstance_Impl::accept (Visitor * v)
  {
    v->visit_ProvidedRequestPortInstance (this);
  }
}

