// $Id$

#include "stdafx.h"
#include "InEventPortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPortInstance_Impl::metaname = "InEventPortInstance";

  //
  // InEventPortInstance_Impl
  //
  InEventPortInstance_Impl::InEventPortInstance_Impl (void)
  {
  }

  //
  // InEventPortInstance_Impl
  //
  InEventPortInstance_Impl::InEventPortInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InEventPortInstance_Impl
  //
  InEventPortInstance_Impl::~InEventPortInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void InEventPortInstance_Impl::accept (Visitor * v)
  {
    v->visit_InEventPortInstance (this);
  }
}

