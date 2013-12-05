// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // QueryInput_Impl
  //
  GAME_INLINE QueryInput_Impl::QueryInput_Impl (void)
  {
  }

  //
  // QueryInput_Impl
  //
  GAME_INLINE QueryInput_Impl::QueryInput_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~QueryInput_Impl
  //
  GAME_INLINE QueryInput_Impl::~QueryInput_Impl (void)
  {
  }
}

