// $Id$

#include "stdafx.h"
#include "Capability.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Capability_Impl::metaname = "Capability";

  //
  // Capability_Impl
  //
  Capability_Impl::Capability_Impl (void)
  {
  }

  //
  // Capability_Impl
  //
  Capability_Impl::Capability_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Capability_Impl
  //
  Capability_Impl::~Capability_Impl (void)
  {
  }

  //
  // accept
  //
  void Capability_Impl::accept (Visitor * v)
  {
    v->visit_Capability (this);
  }
}

