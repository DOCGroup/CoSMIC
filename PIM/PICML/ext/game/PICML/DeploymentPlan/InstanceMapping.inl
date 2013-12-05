// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // InstanceMapping_Impl
  //
  GAME_INLINE InstanceMapping_Impl::InstanceMapping_Impl (void)
  {
  }

  //
  // InstanceMapping_Impl
  //
  GAME_INLINE InstanceMapping_Impl::InstanceMapping_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InstanceMapping_Impl
  //
  GAME_INLINE InstanceMapping_Impl::~InstanceMapping_Impl (void)
  {
  }
}

