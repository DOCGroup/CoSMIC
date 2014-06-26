// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // WriterDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE WriterDataLifecycleQosPolicy_Impl::WriterDataLifecycleQosPolicy_Impl (void)
  {
  }

  //
  // WriterDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE WriterDataLifecycleQosPolicy_Impl::WriterDataLifecycleQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WriterDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE WriterDataLifecycleQosPolicy_Impl::~WriterDataLifecycleQosPolicy_Impl (void)
  {
  }

  //
  // autodispose_unregistered_instances
  //
  GAME_INLINE void WriterDataLifecycleQosPolicy_Impl::autodispose_unregistered_instances (bool val)
  {
    static const std::string attr_name ("autodispose_unregistered_instances");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // autodispose_unregistered_instances
  //
  GAME_INLINE bool WriterDataLifecycleQosPolicy_Impl::autodispose_unregistered_instances (void) const
  {
    static const std::string attr_name ("autodispose_unregistered_instances");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // autopurge_suspended_samples_delay
  //
  GAME_INLINE void WriterDataLifecycleQosPolicy_Impl::autopurge_suspended_samples_delay (double val)
  {
    static const std::string attr_name ("autopurge_suspended_samples_delay");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // autopurge_suspended_samples_delay
  //
  GAME_INLINE double WriterDataLifecycleQosPolicy_Impl::autopurge_suspended_samples_delay (void) const
  {
    static const std::string attr_name ("autopurge_suspended_samples_delay");
    return this->attribute (attr_name)->double_value ();
  }

  //
  // autounregister_instance_delay
  //
  GAME_INLINE void WriterDataLifecycleQosPolicy_Impl::autounregister_instance_delay (double val)
  {
    static const std::string attr_name ("autounregister_instance_delay");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // autounregister_instance_delay
  //
  GAME_INLINE double WriterDataLifecycleQosPolicy_Impl::autounregister_instance_delay (void) const
  {
    static const std::string attr_name ("autounregister_instance_delay");
    return this->attribute (attr_name)->double_value ();
  }
}

