// $Id$

#include "stdafx.h"
#include "ImplementationRequirement.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationRequirement_Impl::metaname = "ImplementationRequirement";

  //
  // ImplementationRequirement_Impl
  //
  ImplementationRequirement_Impl::ImplementationRequirement_Impl (void)
  {
  }

  //
  // ImplementationRequirement_Impl
  //
  ImplementationRequirement_Impl::ImplementationRequirement_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationRequirement_Impl
  //
  ImplementationRequirement_Impl::~ImplementationRequirement_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationRequirement_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationRequirement (this);
  }
}

