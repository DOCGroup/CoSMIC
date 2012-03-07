// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ExternalDelegate_Impl
  //
  GAME_INLINE ExternalDelegate_Impl::ExternalDelegate_Impl (void)
  {
  }

  //
  // ExternalDelegate_Impl
  //
  GAME_INLINE ExternalDelegate_Impl::ExternalDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExternalDelegate_Impl
  //
  GAME_INLINE ExternalDelegate_Impl::~ExternalDelegate_Impl (void)
  {
  }
}

