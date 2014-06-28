// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Publish_Impl
  //
  GAME_INLINE Publish_Impl::Publish_Impl (void)
  {
  }

  //
  // Publish_Impl
  //
  GAME_INLINE Publish_Impl::Publish_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Publish_Impl
  //
  GAME_INLINE Publish_Impl::~Publish_Impl (void)
  {
  }
}

