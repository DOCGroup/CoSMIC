// -*- C++ -*-
namespace PICML
{
  //
  // ComponentImplementationReference_Impl
  //
  GAME_INLINE ComponentImplementationReference_Impl::ComponentImplementationReference_Impl (void)
  {
  }

  //
  // ComponentImplementationReference_Impl
  //
  GAME_INLINE ComponentImplementationReference_Impl::ComponentImplementationReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementationReference_Impl
  //
  GAME_INLINE ComponentImplementationReference_Impl::~ComponentImplementationReference_Impl (void)
  {
  }
}

