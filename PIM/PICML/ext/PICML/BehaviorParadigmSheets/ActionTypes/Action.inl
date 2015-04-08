// -*- C++ -*-
namespace PICML
{
  //
  // Action_Impl
  //
  GAME_INLINE Action_Impl::Action_Impl (void)
  {
  }

  //
  // Action_Impl
  //
  GAME_INLINE Action_Impl::Action_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Action_Impl
  //
  GAME_INLINE Action_Impl::~Action_Impl (void)
  {
  }
}

