// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // DataType_Impl
  //
  GAME_INLINE DataType_Impl::DataType_Impl (void)
  {
  }

  //
  // DataType_Impl
  //
  GAME_INLINE DataType_Impl::DataType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataType_Impl
  //
  GAME_INLINE DataType_Impl::~DataType_Impl (void)
  {
  }
}

