// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // DeploymentPlan_Impl
  //
  GAME_INLINE DeploymentPlan_Impl::DeploymentPlan_Impl (void)
  {
  }

  //
  // DeploymentPlan_Impl
  //
  GAME_INLINE DeploymentPlan_Impl::DeploymentPlan_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DeploymentPlan_Impl
  //
  GAME_INLINE DeploymentPlan_Impl::~DeploymentPlan_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void DeploymentPlan_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string DeploymentPlan_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void DeploymentPlan_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string DeploymentPlan_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

