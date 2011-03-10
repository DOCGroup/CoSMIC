// $Id$

#include "stdafx.h"
#include "ExceptionType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExceptionType_Impl::metaname = "ExceptionType";

  //
  // ExceptionType_Impl
  //
  ExceptionType_Impl::ExceptionType_Impl (void)
  {
  }

  //
  // ExceptionType_Impl
  //
  ExceptionType_Impl::ExceptionType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExceptionType_Impl
  //
  ExceptionType_Impl::~ExceptionType_Impl (void)
  {
  }
}

