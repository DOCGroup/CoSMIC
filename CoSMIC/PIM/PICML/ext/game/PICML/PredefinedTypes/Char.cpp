// $Id$

#include "stdafx.h"
#include "Char.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Char_Impl::metaname = "Char";

  //
  // Char_Impl
  //
  Char_Impl::Char_Impl (void)
  {
  }

  //
  // Char_Impl
  //
  Char_Impl::Char_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Char_Impl
  //
  Char_Impl::~Char_Impl (void)
  {
  }

  //
  // accept
  //
  void Char_Impl::accept (Visitor * v)
  {
    v->visit_Char (this);
  }
}

