// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // NativeValue_Impl
  //
  GAME_INLINE NativeValue_Impl::NativeValue_Impl (void)
  {
  }

  //
  // NativeValue_Impl
  //
  GAME_INLINE NativeValue_Impl::NativeValue_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NativeValue_Impl
  //
  GAME_INLINE NativeValue_Impl::~NativeValue_Impl (void)
  {
  }
}

