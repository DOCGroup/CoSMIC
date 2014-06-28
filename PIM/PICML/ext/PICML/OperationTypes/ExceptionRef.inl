// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ExceptionRef_Impl
  //
  GAME_INLINE ExceptionRef_Impl::ExceptionRef_Impl (void)
  {
  }

  //
  // ExceptionRef_Impl
  //
  GAME_INLINE ExceptionRef_Impl::ExceptionRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExceptionRef_Impl
  //
  GAME_INLINE ExceptionRef_Impl::~ExceptionRef_Impl (void)
  {
  }
}

