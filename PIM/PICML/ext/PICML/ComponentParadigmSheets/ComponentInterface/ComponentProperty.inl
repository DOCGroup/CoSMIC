// -*- C++ -*-
namespace PICML
{
  //
  // ComponentProperty_Impl
  //
  GAME_INLINE ComponentProperty_Impl::ComponentProperty_Impl (void)
  {
  }

  //
  // ComponentProperty_Impl
  //
  GAME_INLINE ComponentProperty_Impl::ComponentProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentProperty_Impl
  //
  GAME_INLINE ComponentProperty_Impl::~ComponentProperty_Impl (void)
  {
  }
}

