// $Id$

#include "stdafx.h"
#include "Requirement.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Requirement_Impl::metaname = "Requirement";

  //
  // Requirement_Impl
  //
  Requirement_Impl::Requirement_Impl (void)
  {
  }

  //
  // Requirement_Impl
  //
  Requirement_Impl::Requirement_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Requirement_Impl
  //
  Requirement_Impl::~Requirement_Impl (void)
  {
  }

  //
  // accept
  //
  void Requirement_Impl::accept (Visitor * v)
  {
    v->visit_Requirement (this);
  }
}

