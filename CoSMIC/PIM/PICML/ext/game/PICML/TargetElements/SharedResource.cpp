// $Id$

#include "stdafx.h"
#include "SharedResource.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SharedResource_Impl::metaname = "SharedResource";

  //
  // SharedResource_Impl
  //
  SharedResource_Impl::SharedResource_Impl (void)
  {
  }

  //
  // SharedResource_Impl
  //
  SharedResource_Impl::SharedResource_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SharedResource_Impl
  //
  SharedResource_Impl::~SharedResource_Impl (void)
  {
  }

  //
  // accept
  //
  void SharedResource_Impl::accept (Visitor * v)
  {
    v->visit_SharedResource (this);
  }
}

