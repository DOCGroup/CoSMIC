// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // FileRef_Impl
  //
  GAME_INLINE FileRef_Impl::FileRef_Impl (void)
  {
  }

  //
  // FileRef_Impl
  //
  GAME_INLINE FileRef_Impl::FileRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FileRef_Impl
  //
  GAME_INLINE FileRef_Impl::~FileRef_Impl (void)
  {
  }
}

