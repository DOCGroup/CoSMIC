// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // ResourceLimitsQosPolicy_Impl
  //
  GAME_INLINE ResourceLimitsQosPolicy_Impl::ResourceLimitsQosPolicy_Impl (void)
  {
  }

  //
  // ResourceLimitsQosPolicy_Impl
  //
  GAME_INLINE ResourceLimitsQosPolicy_Impl::ResourceLimitsQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ResourceLimitsQosPolicy_Impl
  //
  GAME_INLINE ResourceLimitsQosPolicy_Impl::~ResourceLimitsQosPolicy_Impl (void)
  {
  }

  //
  // max_samples
  //
  GAME_INLINE void ResourceLimitsQosPolicy_Impl::max_samples (long val)
  {
    static const std::string attr_name ("max_samples");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // max_samples
  //
  GAME_INLINE long ResourceLimitsQosPolicy_Impl::max_samples (void) const
  {
    static const std::string attr_name ("max_samples");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // max_instances
  //
  GAME_INLINE void ResourceLimitsQosPolicy_Impl::max_instances (long val)
  {
    static const std::string attr_name ("max_instances");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // max_instances
  //
  GAME_INLINE long ResourceLimitsQosPolicy_Impl::max_instances (void) const
  {
    static const std::string attr_name ("max_instances");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // max_samples_per_instance
  //
  GAME_INLINE void ResourceLimitsQosPolicy_Impl::max_samples_per_instance (long val)
  {
    static const std::string attr_name ("max_samples_per_instance");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // max_samples_per_instance
  //
  GAME_INLINE long ResourceLimitsQosPolicy_Impl::max_samples_per_instance (void) const
  {
    static const std::string attr_name ("max_samples_per_instance");
    return this->attribute (attr_name)->int_value ();
  }
}

