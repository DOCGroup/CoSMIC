// -*- C++ -*-
namespace PICML
{
  //
  // ConfigProperty_Impl
  //
  GAME_INLINE ConfigProperty_Impl::ConfigProperty_Impl (void)
  {
  }

  //
  // ConfigProperty_Impl
  //
  GAME_INLINE ConfigProperty_Impl::ConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConfigProperty_Impl
  //
  GAME_INLINE ConfigProperty_Impl::~ConfigProperty_Impl (void)
  {
  }
}

