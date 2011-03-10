// $Id$

#include "stdafx.h"
#include "GenericValue.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GenericValue_Impl::metaname = "GenericValue";

  //
  // GenericValue_Impl
  //
  GenericValue_Impl::GenericValue_Impl (void)
  {
  }

  //
  // GenericValue_Impl
  //
  GenericValue_Impl::GenericValue_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GenericValue_Impl
  //
  GenericValue_Impl::~GenericValue_Impl (void)
  {
  }

  //
  // accept
  //
  void GenericValue_Impl::accept (Visitor * v)
  {
    v->visit_GenericValue (this);
  }
}

