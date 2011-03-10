// $Id$

#include "stdafx.h"
#include "OutEventPortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPortInstance_Impl::metaname = "OutEventPortInstance";

  //
  // OutEventPortInstance_Impl
  //
  OutEventPortInstance_Impl::OutEventPortInstance_Impl (void)
  {
  }

  //
  // OutEventPortInstance_Impl
  //
  OutEventPortInstance_Impl::OutEventPortInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutEventPortInstance_Impl
  //
  OutEventPortInstance_Impl::~OutEventPortInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void OutEventPortInstance_Impl::accept (Visitor * v)
  {
    v->visit_OutEventPortInstance (this);
  }
}

