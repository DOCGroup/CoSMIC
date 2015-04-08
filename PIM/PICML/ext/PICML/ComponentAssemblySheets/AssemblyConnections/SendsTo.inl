// -*- C++ -*-
namespace PICML
{
  //
  // SendsTo_Impl
  //
  GAME_INLINE SendsTo_Impl::SendsTo_Impl (void)
  {
  }

  //
  // SendsTo_Impl
  //
  GAME_INLINE SendsTo_Impl::SendsTo_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SendsTo_Impl
  //
  GAME_INLINE SendsTo_Impl::~SendsTo_Impl (void)
  {
  }
}

