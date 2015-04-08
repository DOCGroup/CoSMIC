// -*- C++ -*-
namespace PICML
{
  //
  // ImplementationRequirement_Impl
  //
  GAME_INLINE ImplementationRequirement_Impl::ImplementationRequirement_Impl (void)
  {
  }

  //
  // ImplementationRequirement_Impl
  //
  GAME_INLINE ImplementationRequirement_Impl::ImplementationRequirement_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationRequirement_Impl
  //
  GAME_INLINE ImplementationRequirement_Impl::~ImplementationRequirement_Impl (void)
  {
  }

  //
  // ResourceUsageKind
  //
  GAME_INLINE void ImplementationRequirement_Impl::ResourceUsageKind (const std::string & val)
  {
    static const std::string attr_name ("ResourceUsageKind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // ResourceUsageKind
  //
  GAME_INLINE std::string ImplementationRequirement_Impl::ResourceUsageKind (void) const
  {
    static const std::string attr_name ("ResourceUsageKind");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // resourcePort
  //
  GAME_INLINE void ImplementationRequirement_Impl::resourcePort (const std::string & val)
  {
    static const std::string attr_name ("resourcePort");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // resourcePort
  //
  GAME_INLINE std::string ImplementationRequirement_Impl::resourcePort (void) const
  {
    static const std::string attr_name ("resourcePort");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // componentPort
  //
  GAME_INLINE void ImplementationRequirement_Impl::componentPort (const std::string & val)
  {
    static const std::string attr_name ("componentPort");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // componentPort
  //
  GAME_INLINE std::string ImplementationRequirement_Impl::componentPort (void) const
  {
    static const std::string attr_name ("componentPort");
    return this->attribute (attr_name)->string_value ();
  }
}

