// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ValueObject_Impl
  //
  GAME_INLINE ValueObject_Impl::ValueObject_Impl (void)
  {
  }

  //
  // ValueObject_Impl
  //
  GAME_INLINE ValueObject_Impl::ValueObject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ValueObject_Impl
  //
  GAME_INLINE ValueObject_Impl::~ValueObject_Impl (void)
  {
  }
}

