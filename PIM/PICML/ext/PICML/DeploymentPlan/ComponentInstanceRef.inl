// -*- C++ -*-
namespace PICML
{
  //
  // ComponentInstanceRef_Impl
  //
  GAME_INLINE ComponentInstanceRef_Impl::ComponentInstanceRef_Impl (void)
  {
  }

  //
  // ComponentInstanceRef_Impl
  //
  GAME_INLINE ComponentInstanceRef_Impl::ComponentInstanceRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInstanceRef_Impl
  //
  GAME_INLINE ComponentInstanceRef_Impl::~ComponentInstanceRef_Impl (void)
  {
  }
}

