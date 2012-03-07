// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentPackage_Impl
  //
  GAME_INLINE ComponentPackage_Impl::ComponentPackage_Impl (void)
  {
  }

  //
  // ComponentPackage_Impl
  //
  GAME_INLINE ComponentPackage_Impl::ComponentPackage_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentPackage_Impl
  //
  GAME_INLINE ComponentPackage_Impl::~ComponentPackage_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void ComponentPackage_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string ComponentPackage_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void ComponentPackage_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string ComponentPackage_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

