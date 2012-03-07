// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // DataValueBase_Impl
  //
  GAME_INLINE DataValueBase_Impl::DataValueBase_Impl (void)
  {
  }

  //
  // DataValueBase_Impl
  //
  GAME_INLINE DataValueBase_Impl::DataValueBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataValueBase_Impl
  //
  GAME_INLINE DataValueBase_Impl::~DataValueBase_Impl (void)
  {
  }
}

