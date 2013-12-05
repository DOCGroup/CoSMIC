// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Requirement_Impl
  //
  GAME_INLINE Requirement_Impl::Requirement_Impl (void)
  {
  }

  //
  // Requirement_Impl
  //
  GAME_INLINE Requirement_Impl::Requirement_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Requirement_Impl
  //
  GAME_INLINE Requirement_Impl::~Requirement_Impl (void)
  {
  }
}

