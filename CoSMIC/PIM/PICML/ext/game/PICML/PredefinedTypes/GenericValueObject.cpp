// $Id$

#include "stdafx.h"
#include "GenericValueObject.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GenericValueObject_Impl::metaname = "GenericValueObject";

  //
  // GenericValueObject_Impl
  //
  GenericValueObject_Impl::GenericValueObject_Impl (void)
  {
  }

  //
  // GenericValueObject_Impl
  //
  GenericValueObject_Impl::GenericValueObject_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GenericValueObject_Impl
  //
  GenericValueObject_Impl::~GenericValueObject_Impl (void)
  {
  }

  //
  // accept
  //
  void GenericValueObject_Impl::accept (Visitor * v)
  {
    v->visit_GenericValueObject (this);
  }
}

