// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentRef_Impl
  //
  GAME_INLINE ComponentRef_Impl::ComponentRef_Impl (void)
  {
  }

  //
  // ComponentRef_Impl
  //
  GAME_INLINE ComponentRef_Impl::ComponentRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentRef_Impl
  //
  GAME_INLINE ComponentRef_Impl::~ComponentRef_Impl (void)
  {
  }
}

