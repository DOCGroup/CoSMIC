// $Id$

#include "stdafx.h"
#include "SingleOutputBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SingleOutputBase_Impl::metaname = "SingleOutputBase";

  //
  // SingleOutputBase_Impl
  //
  SingleOutputBase_Impl::SingleOutputBase_Impl (void)
  {
  }

  //
  // SingleOutputBase_Impl
  //
  SingleOutputBase_Impl::SingleOutputBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SingleOutputBase_Impl
  //
  SingleOutputBase_Impl::~SingleOutputBase_Impl (void)
  {
  }
}

