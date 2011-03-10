// $Id$

#include "stdafx.h"
#include "RequiredRequestPortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPortInstance_Impl::metaname = "RequiredRequestPortInstance";

  //
  // RequiredRequestPortInstance_Impl
  //
  RequiredRequestPortInstance_Impl::RequiredRequestPortInstance_Impl (void)
  {
  }

  //
  // RequiredRequestPortInstance_Impl
  //
  RequiredRequestPortInstance_Impl::RequiredRequestPortInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequiredRequestPortInstance_Impl
  //
  RequiredRequestPortInstance_Impl::~RequiredRequestPortInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void RequiredRequestPortInstance_Impl::accept (Visitor * v)
  {
    v->visit_RequiredRequestPortInstance (this);
  }
}

