// -*- C++ -*-
namespace PICML
{
  //
  // ComponentFactoryRef_Impl
  //
  GAME_INLINE ComponentFactoryRef_Impl::ComponentFactoryRef_Impl (void)
  {
  }

  //
  // ComponentFactoryRef_Impl
  //
  GAME_INLINE ComponentFactoryRef_Impl::ComponentFactoryRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryRef_Impl
  //
  GAME_INLINE ComponentFactoryRef_Impl::~ComponentFactoryRef_Impl (void)
  {
  }
}

