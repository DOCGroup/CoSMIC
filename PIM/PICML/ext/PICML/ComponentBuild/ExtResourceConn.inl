// -*- C++ -*-
namespace PICML
{
  //
  // ExtResourceConn_Impl
  //
  GAME_INLINE ExtResourceConn_Impl::ExtResourceConn_Impl (void)
  {
  }

  //
  // ExtResourceConn_Impl
  //
  GAME_INLINE ExtResourceConn_Impl::ExtResourceConn_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtResourceConn_Impl
  //
  GAME_INLINE ExtResourceConn_Impl::~ExtResourceConn_Impl (void)
  {
  }
}

