// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ReadonlyAttribute_Impl
  //
  GAME_INLINE ReadonlyAttribute_Impl::ReadonlyAttribute_Impl (void)
  {
  }

  //
  // ReadonlyAttribute_Impl
  //
  GAME_INLINE ReadonlyAttribute_Impl::ReadonlyAttribute_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReadonlyAttribute_Impl
  //
  GAME_INLINE ReadonlyAttribute_Impl::~ReadonlyAttribute_Impl (void)
  {
  }
}

