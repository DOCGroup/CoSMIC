// -*- C++ -*-
namespace PICML
{
  //
  // Consume_Impl
  //
  GAME_INLINE Consume_Impl::Consume_Impl (void)
  {
  }

  //
  // Consume_Impl
  //
  GAME_INLINE Consume_Impl::Consume_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Consume_Impl
  //
  GAME_INLINE Consume_Impl::~Consume_Impl (void)
  {
  }
}

