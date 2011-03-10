// $Id$

#include "stdafx.h"
#include "GenericObject.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GenericObject_Impl::metaname = "GenericObject";

  //
  // GenericObject_Impl
  //
  GenericObject_Impl::GenericObject_Impl (void)
  {
  }

  //
  // GenericObject_Impl
  //
  GenericObject_Impl::GenericObject_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GenericObject_Impl
  //
  GenericObject_Impl::~GenericObject_Impl (void)
  {
  }

  //
  // accept
  //
  void GenericObject_Impl::accept (Visitor * v)
  {
    v->visit_GenericObject (this);
  }
}

