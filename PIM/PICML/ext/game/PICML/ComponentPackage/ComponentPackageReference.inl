// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentPackageReference_Impl
  //
  GAME_INLINE ComponentPackageReference_Impl::ComponentPackageReference_Impl (void)
  {
  }

  //
  // ComponentPackageReference_Impl
  //
  GAME_INLINE ComponentPackageReference_Impl::ComponentPackageReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentPackageReference_Impl
  //
  GAME_INLINE ComponentPackageReference_Impl::~ComponentPackageReference_Impl (void)
  {
  }

  //
  // requiredUUID
  //
  GAME_INLINE void ComponentPackageReference_Impl::requiredUUID (const std::string & val)
  {
    static const std::string attr_name ("requiredUUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // requiredUUID
  //
  GAME_INLINE std::string ComponentPackageReference_Impl::requiredUUID (void) const
  {
    static const std::string attr_name ("requiredUUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // requiredName
  //
  GAME_INLINE void ComponentPackageReference_Impl::requiredName (const std::string & val)
  {
    static const std::string attr_name ("requiredName");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // requiredName
  //
  GAME_INLINE std::string ComponentPackageReference_Impl::requiredName (void) const
  {
    static const std::string attr_name ("requiredName");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // requiredType
  //
  GAME_INLINE void ComponentPackageReference_Impl::requiredType (const std::string & val)
  {
    static const std::string attr_name ("requiredType");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // requiredType
  //
  GAME_INLINE std::string ComponentPackageReference_Impl::requiredType (void) const
  {
    static const std::string attr_name ("requiredType");
    return this->attribute (attr_name)->string_value ();
  }
}

