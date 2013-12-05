// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // TypeParameter_Impl
  //
  GAME_INLINE TypeParameter_Impl::TypeParameter_Impl (void)
  {
  }

  //
  // TypeParameter_Impl
  //
  GAME_INLINE TypeParameter_Impl::TypeParameter_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TypeParameter_Impl
  //
  GAME_INLINE TypeParameter_Impl::~TypeParameter_Impl (void)
  {
  }

  //
  // Type
  //
  GAME_INLINE void TypeParameter_Impl::Type (const std::string & val)
  {
    static const std::string attr_name ("Type");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Type
  //
  GAME_INLINE std::string TypeParameter_Impl::Type (void) const
  {
    static const std::string attr_name ("Type");
    return this->attribute (attr_name)->string_value ();
  }
}

