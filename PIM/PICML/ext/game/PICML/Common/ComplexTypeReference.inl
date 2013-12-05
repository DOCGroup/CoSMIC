// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComplexTypeReference_Impl
  //
  GAME_INLINE ComplexTypeReference_Impl::ComplexTypeReference_Impl (void)
  {
  }

  //
  // ComplexTypeReference_Impl
  //
  GAME_INLINE ComplexTypeReference_Impl::ComplexTypeReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComplexTypeReference_Impl
  //
  GAME_INLINE ComplexTypeReference_Impl::~ComplexTypeReference_Impl (void)
  {
  }
}

