// $Id$

#include "stdafx.h"
#include "NoInheritable.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string NoInheritable_Impl::metaname = "NoInheritable";

  //
  // NoInheritable_Impl
  //
  NoInheritable_Impl::NoInheritable_Impl (void)
  {
  }

  //
  // NoInheritable_Impl
  //
  NoInheritable_Impl::NoInheritable_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NoInheritable_Impl
  //
  NoInheritable_Impl::~NoInheritable_Impl (void)
  {
  }
}

