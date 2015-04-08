// -*- C++ -*-
namespace DQML
{
  //
  // Domain_Impl
  //
  GAME_INLINE Domain_Impl::Domain_Impl (void)
  {
  }

  //
  // Domain_Impl
  //
  GAME_INLINE Domain_Impl::Domain_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Domain_Impl
  //
  GAME_INLINE Domain_Impl::~Domain_Impl (void)
  {
  }
}

