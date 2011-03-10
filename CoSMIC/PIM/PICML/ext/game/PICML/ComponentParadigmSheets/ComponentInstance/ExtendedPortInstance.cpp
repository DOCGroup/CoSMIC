// $Id$

#include "stdafx.h"
#include "ExtendedPortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortInstance_Impl::metaname = "ExtendedPortInstance";

  //
  // ExtendedPortInstance_Impl
  //
  ExtendedPortInstance_Impl::ExtendedPortInstance_Impl (void)
  {
  }

  //
  // ExtendedPortInstance_Impl
  //
  ExtendedPortInstance_Impl::ExtendedPortInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendedPortInstance_Impl
  //
  ExtendedPortInstance_Impl::~ExtendedPortInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void ExtendedPortInstance_Impl::accept (Visitor * v)
  {
    v->visit_ExtendedPortInstance (this);
  }
}

