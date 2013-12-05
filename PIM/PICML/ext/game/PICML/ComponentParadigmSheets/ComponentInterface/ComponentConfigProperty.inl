// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentConfigProperty_Impl
  //
  GAME_INLINE ComponentConfigProperty_Impl::ComponentConfigProperty_Impl (void)
  {
  }

  //
  // ComponentConfigProperty_Impl
  //
  GAME_INLINE ComponentConfigProperty_Impl::ComponentConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentConfigProperty_Impl
  //
  GAME_INLINE ComponentConfigProperty_Impl::~ComponentConfigProperty_Impl (void)
  {
  }
}

