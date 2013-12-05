// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // TerminalTransition_Impl
  //
  GAME_INLINE TerminalTransition_Impl::TerminalTransition_Impl (void)
  {
  }

  //
  // TerminalTransition_Impl
  //
  GAME_INLINE TerminalTransition_Impl::TerminalTransition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TerminalTransition_Impl
  //
  GAME_INLINE TerminalTransition_Impl::~TerminalTransition_Impl (void)
  {
  }
}

