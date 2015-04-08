// -*- C++ -*-
namespace PICML
{
  //
  // ArrayMember_Impl
  //
  GAME_INLINE ArrayMember_Impl::ArrayMember_Impl (void)
  {
  }

  //
  // ArrayMember_Impl
  //
  GAME_INLINE ArrayMember_Impl::ArrayMember_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ArrayMember_Impl
  //
  GAME_INLINE ArrayMember_Impl::~ArrayMember_Impl (void)
  {
  }

  //
  // Size
  //
  GAME_INLINE void ArrayMember_Impl::Size (long val)
  {
    static const std::string attr_name ("Size");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // Size
  //
  GAME_INLINE long ArrayMember_Impl::Size (void) const
  {
    static const std::string attr_name ("Size");
    return this->attribute (attr_name)->int_value ();
  }
}

