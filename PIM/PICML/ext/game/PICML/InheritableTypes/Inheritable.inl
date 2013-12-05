// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Inheritable_Impl
  //
  GAME_INLINE Inheritable_Impl::Inheritable_Impl (void)
  {
  }

  //
  // Inheritable_Impl
  //
  GAME_INLINE Inheritable_Impl::Inheritable_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Inheritable_Impl
  //
  GAME_INLINE Inheritable_Impl::~Inheritable_Impl (void)
  {
  }
}

