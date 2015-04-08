// -*- C++ -*-
namespace PICML
{
  //
  // AttributeDelegate_Impl
  //
  GAME_INLINE AttributeDelegate_Impl::AttributeDelegate_Impl (void)
  {
  }

  //
  // AttributeDelegate_Impl
  //
  GAME_INLINE AttributeDelegate_Impl::AttributeDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeDelegate_Impl
  //
  GAME_INLINE AttributeDelegate_Impl::~AttributeDelegate_Impl (void)
  {
  }
}

