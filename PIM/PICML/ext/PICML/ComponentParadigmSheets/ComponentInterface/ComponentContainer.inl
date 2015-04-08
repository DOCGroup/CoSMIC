// -*- C++ -*-
namespace PICML
{
  //
  // ComponentContainer_Impl
  //
  GAME_INLINE ComponentContainer_Impl::ComponentContainer_Impl (void)
  {
  }

  //
  // ComponentContainer_Impl
  //
  GAME_INLINE ComponentContainer_Impl::ComponentContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentContainer_Impl
  //
  GAME_INLINE ComponentContainer_Impl::~ComponentContainer_Impl (void)
  {
  }
}

