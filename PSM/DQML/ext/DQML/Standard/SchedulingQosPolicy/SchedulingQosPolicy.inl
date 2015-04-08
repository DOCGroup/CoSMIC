// -*- C++ -*-
namespace DQML
{
  //
  // SchedulingQosPolicy_Impl
  //
  GAME_INLINE SchedulingQosPolicy_Impl::SchedulingQosPolicy_Impl (void)
  {
  }

  //
  // SchedulingQosPolicy_Impl
  //
  GAME_INLINE SchedulingQosPolicy_Impl::SchedulingQosPolicy_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SchedulingQosPolicy_Impl
  //
  GAME_INLINE SchedulingQosPolicy_Impl::~SchedulingQosPolicy_Impl (void)
  {
  }

  //
  // scheduling_priority
  //
  GAME_INLINE void SchedulingQosPolicy_Impl::scheduling_priority (long val)
  {
    static const std::string attr_name ("scheduling_priority");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // scheduling_priority
  //
  GAME_INLINE long SchedulingQosPolicy_Impl::scheduling_priority (void) const
  {
    static const std::string attr_name ("scheduling_priority");
    return this->attribute (attr_name)->int_value ();
  }
}

