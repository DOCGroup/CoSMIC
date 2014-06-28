// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // SchedulingClassQosPolicy_Impl
  //
  GAME_INLINE SchedulingClassQosPolicy_Impl::SchedulingClassQosPolicy_Impl (void)
  {
  }

  //
  // SchedulingClassQosPolicy_Impl
  //
  GAME_INLINE SchedulingClassQosPolicy_Impl::SchedulingClassQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SchedulingClassQosPolicy_Impl
  //
  GAME_INLINE SchedulingClassQosPolicy_Impl::~SchedulingClassQosPolicy_Impl (void)
  {
  }

  //
  // scheduling_class_kind
  //
  GAME_INLINE void SchedulingClassQosPolicy_Impl::scheduling_class_kind (const std::string & val)
  {
    static const std::string attr_name ("scheduling_class_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // scheduling_class_kind
  //
  GAME_INLINE std::string SchedulingClassQosPolicy_Impl::scheduling_class_kind (void) const
  {
    static const std::string attr_name ("scheduling_class_kind");
    return this->attribute (attr_name)->string_value ();
  }
}

