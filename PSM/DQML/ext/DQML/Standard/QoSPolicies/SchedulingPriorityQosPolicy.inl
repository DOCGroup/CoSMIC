// -*- C++ -*-
namespace DQML
{
  //
  // SchedulingPriorityQosPolicy_Impl
  //
  GAME_INLINE SchedulingPriorityQosPolicy_Impl::SchedulingPriorityQosPolicy_Impl (void)
  {
  }

  //
  // SchedulingPriorityQosPolicy_Impl
  //
  GAME_INLINE SchedulingPriorityQosPolicy_Impl::SchedulingPriorityQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SchedulingPriorityQosPolicy_Impl
  //
  GAME_INLINE SchedulingPriorityQosPolicy_Impl::~SchedulingPriorityQosPolicy_Impl (void)
  {
  }

  //
  // scheduling_priority_kind
  //
  GAME_INLINE void SchedulingPriorityQosPolicy_Impl::scheduling_priority_kind (const std::string & val)
  {
    static const std::string attr_name ("scheduling_priority_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // scheduling_priority_kind
  //
  GAME_INLINE std::string SchedulingPriorityQosPolicy_Impl::scheduling_priority_kind (void) const
  {
    static const std::string attr_name ("scheduling_priority_kind");
    return this->attribute (attr_name)->string_value ();
  }
}

