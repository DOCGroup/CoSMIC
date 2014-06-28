// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // OperationBase_Impl
  //
  GAME_INLINE OperationBase_Impl::OperationBase_Impl (void)
  {
  }

  //
  // OperationBase_Impl
  //
  GAME_INLINE OperationBase_Impl::OperationBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OperationBase_Impl
  //
  GAME_INLINE OperationBase_Impl::~OperationBase_Impl (void)
  {
  }
}

