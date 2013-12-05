// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Invoke_Impl
  //
  GAME_INLINE Invoke_Impl::Invoke_Impl (void)
  {
  }

  //
  // Invoke_Impl
  //
  GAME_INLINE Invoke_Impl::Invoke_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Invoke_Impl
  //
  GAME_INLINE Invoke_Impl::~Invoke_Impl (void)
  {
  }
}

