// -*- C++ -*-
namespace PICML
{
  //
  // ManagesComponent_Impl
  //
  GAME_INLINE ManagesComponent_Impl::ManagesComponent_Impl (void)
  {
  }

  //
  // ManagesComponent_Impl
  //
  GAME_INLINE ManagesComponent_Impl::ManagesComponent_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ManagesComponent_Impl
  //
  GAME_INLINE ManagesComponent_Impl::~ManagesComponent_Impl (void)
  {
  }
}

