// -*- C++ -*-
namespace PICML
{
  //
  // GenericValueObject_Impl
  //
  GAME_INLINE GenericValueObject_Impl::GenericValueObject_Impl (void)
  {
  }

  //
  // GenericValueObject_Impl
  //
  GAME_INLINE GenericValueObject_Impl::GenericValueObject_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GenericValueObject_Impl
  //
  GAME_INLINE GenericValueObject_Impl::~GenericValueObject_Impl (void)
  {
  }
}

