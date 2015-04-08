// -*- C++ -*-
namespace PICML
{
  //
  // PackageConfiguration_Impl
  //
  GAME_INLINE PackageConfiguration_Impl::PackageConfiguration_Impl (void)
  {
  }

  //
  // PackageConfiguration_Impl
  //
  GAME_INLINE PackageConfiguration_Impl::PackageConfiguration_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfiguration_Impl
  //
  GAME_INLINE PackageConfiguration_Impl::~PackageConfiguration_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void PackageConfiguration_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string PackageConfiguration_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void PackageConfiguration_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string PackageConfiguration_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

