// $Id$

#include "stdafx.h"
#include "MultiOutputBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MultiOutputBase_Impl::metaname = "MultiOutputBase";

  //
  // MultiOutputBase_Impl
  //
  MultiOutputBase_Impl::MultiOutputBase_Impl (void)
  {
  }

  //
  // MultiOutputBase_Impl
  //
  MultiOutputBase_Impl::MultiOutputBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MultiOutputBase_Impl
  //
  MultiOutputBase_Impl::~MultiOutputBase_Impl (void)
  {
  }
}

