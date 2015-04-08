// -*- C++ -*-
namespace PICML
{
  //
  // CompRef_Impl
  //
  GAME_INLINE CompRef_Impl::CompRef_Impl (void)
  {
  }

  //
  // CompRef_Impl
  //
  GAME_INLINE CompRef_Impl::CompRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CompRef_Impl
  //
  GAME_INLINE CompRef_Impl::~CompRef_Impl (void)
  {
  }
}

