// -*- C++ -*-
namespace PICML
{
  //
  // ComponentOperation_Impl
  //
  GAME_INLINE ComponentOperation_Impl::ComponentOperation_Impl (void)
  {
  }

  //
  // ComponentOperation_Impl
  //
  GAME_INLINE ComponentOperation_Impl::ComponentOperation_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentOperation_Impl
  //
  GAME_INLINE ComponentOperation_Impl::~ComponentOperation_Impl (void)
  {
  }
}

