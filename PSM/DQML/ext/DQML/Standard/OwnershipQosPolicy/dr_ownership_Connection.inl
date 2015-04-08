// -*- C++ -*-
namespace DQML
{
  //
  // dr_ownership_Connection_Impl
  //
  GAME_INLINE dr_ownership_Connection_Impl::dr_ownership_Connection_Impl (void)
  {
  }

  //
  // dr_ownership_Connection_Impl
  //
  GAME_INLINE dr_ownership_Connection_Impl::dr_ownership_Connection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~dr_ownership_Connection_Impl
  //
  GAME_INLINE dr_ownership_Connection_Impl::~dr_ownership_Connection_Impl (void)
  {
  }
}

