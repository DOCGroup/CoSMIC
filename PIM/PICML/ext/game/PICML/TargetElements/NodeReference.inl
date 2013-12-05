// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // NodeReference_Impl
  //
  GAME_INLINE NodeReference_Impl::NodeReference_Impl (void)
  {
  }

  //
  // NodeReference_Impl
  //
  GAME_INLINE NodeReference_Impl::NodeReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NodeReference_Impl
  //
  GAME_INLINE NodeReference_Impl::~NodeReference_Impl (void)
  {
  }
}

