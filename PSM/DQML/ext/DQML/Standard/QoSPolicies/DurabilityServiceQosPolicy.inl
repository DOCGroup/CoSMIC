// -*- C++ -*-
namespace DQML
{
  //
  // DurabilityServiceQosPolicy_Impl
  //
  GAME_INLINE DurabilityServiceQosPolicy_Impl::DurabilityServiceQosPolicy_Impl (void)
  {
  }

  //
  // DurabilityServiceQosPolicy_Impl
  //
  GAME_INLINE DurabilityServiceQosPolicy_Impl::DurabilityServiceQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DurabilityServiceQosPolicy_Impl
  //
  GAME_INLINE DurabilityServiceQosPolicy_Impl::~DurabilityServiceQosPolicy_Impl (void)
  {
  }

  //
  // service_cleanup_delay
  //
  GAME_INLINE void DurabilityServiceQosPolicy_Impl::service_cleanup_delay (double val)
  {
    static const std::string attr_name ("service_cleanup_delay");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // service_cleanup_delay
  //
  GAME_INLINE double DurabilityServiceQosPolicy_Impl::service_cleanup_delay (void) const
  {
    static const std::string attr_name ("service_cleanup_delay");
    return this->attribute (attr_name)->double_value ();
  }

  //
  // history_kind
  //
  GAME_INLINE void DurabilityServiceQosPolicy_Impl::history_kind (const std::string & val)
  {
    static const std::string attr_name ("history_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // history_kind
  //
  GAME_INLINE std::string DurabilityServiceQosPolicy_Impl::history_kind (void) const
  {
    static const std::string attr_name ("history_kind");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // history_depth
  //
  GAME_INLINE void DurabilityServiceQosPolicy_Impl::history_depth (long val)
  {
    static const std::string attr_name ("history_depth");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // history_depth
  //
  GAME_INLINE long DurabilityServiceQosPolicy_Impl::history_depth (void) const
  {
    static const std::string attr_name ("history_depth");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // max_samples
  //
  GAME_INLINE void DurabilityServiceQosPolicy_Impl::max_samples (long val)
  {
    static const std::string attr_name ("max_samples");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // max_samples
  //
  GAME_INLINE long DurabilityServiceQosPolicy_Impl::max_samples (void) const
  {
    static const std::string attr_name ("max_samples");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // max_instances
  //
  GAME_INLINE void DurabilityServiceQosPolicy_Impl::max_instances (long val)
  {
    static const std::string attr_name ("max_instances");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // max_instances
  //
  GAME_INLINE long DurabilityServiceQosPolicy_Impl::max_instances (void) const
  {
    static const std::string attr_name ("max_instances");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // max_samples_per_instance
  //
  GAME_INLINE void DurabilityServiceQosPolicy_Impl::max_samples_per_instance (long val)
  {
    static const std::string attr_name ("max_samples_per_instance");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // max_samples_per_instance
  //
  GAME_INLINE long DurabilityServiceQosPolicy_Impl::max_samples_per_instance (void) const
  {
    static const std::string attr_name ("max_samples_per_instance");
    return this->attribute (attr_name)->int_value ();
  }
}

