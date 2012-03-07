// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // RequirementSatisfier_Impl
  //
  GAME_INLINE RequirementSatisfier_Impl::RequirementSatisfier_Impl (void)
  {
  }

  //
  // RequirementSatisfier_Impl
  //
  GAME_INLINE RequirementSatisfier_Impl::RequirementSatisfier_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequirementSatisfier_Impl
  //
  GAME_INLINE RequirementSatisfier_Impl::~RequirementSatisfier_Impl (void)
  {
  }

  //
  // resourceType
  //
  GAME_INLINE void RequirementSatisfier_Impl::resourceType (const std::string & val)
  {
    static const std::string attr_name ("resourceType");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // resourceType
  //
  GAME_INLINE std::string RequirementSatisfier_Impl::resourceType (void) const
  {
    static const std::string attr_name ("resourceType");
    return this->attribute (attr_name)->string_value ();
  }
}

