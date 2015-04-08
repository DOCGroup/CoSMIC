// -*- C++ -*-
namespace PICML
{
  //
  // ComponentFactoryInstance_Impl
  //
  GAME_INLINE ComponentFactoryInstance_Impl::ComponentFactoryInstance_Impl (void)
  {
  }

  //
  // ComponentFactoryInstance_Impl
  //
  GAME_INLINE ComponentFactoryInstance_Impl::ComponentFactoryInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryInstance_Impl
  //
  GAME_INLINE ComponentFactoryInstance_Impl::~ComponentFactoryInstance_Impl (void)
  {
  }
}

