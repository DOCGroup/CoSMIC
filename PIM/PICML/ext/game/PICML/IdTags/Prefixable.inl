// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Prefixable_Impl
  //
  GAME_INLINE Prefixable_Impl::Prefixable_Impl (void)
  {
  }

  //
  // Prefixable_Impl
  //
  GAME_INLINE Prefixable_Impl::Prefixable_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Prefixable_Impl
  //
  GAME_INLINE Prefixable_Impl::~Prefixable_Impl (void)
  {
  }

  //
  // PrefixTag
  //
  GAME_INLINE void Prefixable_Impl::PrefixTag (const std::string & val)
  {
    static const std::string attr_name ("PrefixTag");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // PrefixTag
  //
  GAME_INLINE std::string Prefixable_Impl::PrefixTag (void) const
  {
    static const std::string attr_name ("PrefixTag");
    return this->attribute (attr_name)->string_value ();
  }
}

