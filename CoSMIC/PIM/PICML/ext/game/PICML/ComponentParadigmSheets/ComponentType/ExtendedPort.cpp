// $Id$

#include "stdafx.h"
#include "ExtendedPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPort_Impl::metaname = "ExtendedPort";

  //
  // ExtendedPort_Impl
  //
  ExtendedPort_Impl::ExtendedPort_Impl (void)
  {
  }

  //
  // ExtendedPort_Impl
  //
  ExtendedPort_Impl::ExtendedPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendedPort_Impl
  //
  ExtendedPort_Impl::~ExtendedPort_Impl (void)
  {
  }

  //
  // accept
  //
  void ExtendedPort_Impl::accept (Visitor * v)
  {
    v->visit_ExtendedPort (this);
  }
}

