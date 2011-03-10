// $Id$

#include "stdafx.h"
#include "Byte.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Byte_Impl::metaname = "Byte";

  //
  // Byte_Impl
  //
  Byte_Impl::Byte_Impl (void)
  {
  }

  //
  // Byte_Impl
  //
  Byte_Impl::Byte_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Byte_Impl
  //
  Byte_Impl::~Byte_Impl (void)
  {
  }

  //
  // accept
  //
  void Byte_Impl::accept (Visitor * v)
  {
    v->visit_Byte (this);
  }
}

