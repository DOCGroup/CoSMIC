// $Id$

#include "stdafx.h"
#include "ImplementationDependency.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationDependency_Impl::metaname = "ImplementationDependency";

  //
  // ImplementationDependency_Impl
  //
  ImplementationDependency_Impl::ImplementationDependency_Impl (void)
  {
  }

  //
  // ImplementationDependency_Impl
  //
  ImplementationDependency_Impl::ImplementationDependency_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationDependency_Impl
  //
  ImplementationDependency_Impl::~ImplementationDependency_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationDependency_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationDependency (this);
  }
}

