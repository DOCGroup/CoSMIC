// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // dw_ownership_Connection_Impl
  //
  GAME_INLINE dw_ownership_Connection_Impl::dw_ownership_Connection_Impl (void)
  {
  }

  //
  // dw_ownership_Connection_Impl
  //
  GAME_INLINE dw_ownership_Connection_Impl::dw_ownership_Connection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~dw_ownership_Connection_Impl
  //
  GAME_INLINE dw_ownership_Connection_Impl::~dw_ownership_Connection_Impl (void)
  {
  }
}

