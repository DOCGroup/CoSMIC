// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // StateBase_Impl
  //
  GAME_INLINE StateBase_Impl::StateBase_Impl (void)
  {
  }

  //
  // StateBase_Impl
  //
  GAME_INLINE StateBase_Impl::StateBase_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~StateBase_Impl
  //
  GAME_INLINE StateBase_Impl::~StateBase_Impl (void)
  {
  }
}

