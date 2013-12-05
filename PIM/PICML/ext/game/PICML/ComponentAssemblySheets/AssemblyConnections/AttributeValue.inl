// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // AttributeValue_Impl
  //
  GAME_INLINE AttributeValue_Impl::AttributeValue_Impl (void)
  {
  }

  //
  // AttributeValue_Impl
  //
  GAME_INLINE AttributeValue_Impl::AttributeValue_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeValue_Impl
  //
  GAME_INLINE AttributeValue_Impl::~AttributeValue_Impl (void)
  {
  }
}

