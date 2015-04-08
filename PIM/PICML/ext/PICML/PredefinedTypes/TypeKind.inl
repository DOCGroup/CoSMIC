// -*- C++ -*-
namespace PICML
{
  //
  // TypeKind_Impl
  //
  GAME_INLINE TypeKind_Impl::TypeKind_Impl (void)
  {
  }

  //
  // TypeKind_Impl
  //
  GAME_INLINE TypeKind_Impl::TypeKind_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TypeKind_Impl
  //
  GAME_INLINE TypeKind_Impl::~TypeKind_Impl (void)
  {
  }
}

