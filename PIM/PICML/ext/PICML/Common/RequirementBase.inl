// -*- C++ -*-
namespace PICML
{
  //
  // RequirementBase_Impl
  //
  GAME_INLINE RequirementBase_Impl::RequirementBase_Impl (void)
  {
  }

  //
  // RequirementBase_Impl
  //
  GAME_INLINE RequirementBase_Impl::RequirementBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequirementBase_Impl
  //
  GAME_INLINE RequirementBase_Impl::~RequirementBase_Impl (void)
  {
  }

  //
  // resourceType
  //
  GAME_INLINE void RequirementBase_Impl::resourceType (const std::string & val)
  {
    static const std::string attr_name ("resourceType");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // resourceType
  //
  GAME_INLINE std::string RequirementBase_Impl::resourceType (void) const
  {
    static const std::string attr_name ("resourceType");
    return this->attribute (attr_name)->string_value ();
  }
}

