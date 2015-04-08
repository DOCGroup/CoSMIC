// -*- C++ -*-
namespace PICML
{
  //
  // OperationRef_Impl
  //
  GAME_INLINE OperationRef_Impl::OperationRef_Impl (void)
  {
  }

  //
  // OperationRef_Impl
  //
  GAME_INLINE OperationRef_Impl::OperationRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OperationRef_Impl
  //
  GAME_INLINE OperationRef_Impl::~OperationRef_Impl (void)
  {
  }
}

