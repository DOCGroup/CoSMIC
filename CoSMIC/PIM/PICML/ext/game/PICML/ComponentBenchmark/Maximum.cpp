// $Id$

#include "stdafx.h"
#include "Maximum.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Maximum_Impl::metaname = "Maximum";

  //
  // Maximum_Impl
  //
  Maximum_Impl::Maximum_Impl (void)
  {
  }

  //
  // Maximum_Impl
  //
  Maximum_Impl::Maximum_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Maximum_Impl
  //
  Maximum_Impl::~Maximum_Impl (void)
  {
  }

  //
  // accept
  //
  void Maximum_Impl::accept (Visitor * v)
  {
    v->visit_Maximum (this);
  }
}

