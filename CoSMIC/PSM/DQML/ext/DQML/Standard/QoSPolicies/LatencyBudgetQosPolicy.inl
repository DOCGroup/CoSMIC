// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // LatencyBudgetQosPolicy_Impl
  //
  GAME_INLINE LatencyBudgetQosPolicy_Impl::LatencyBudgetQosPolicy_Impl (void)
  {
  }

  //
  // LatencyBudgetQosPolicy_Impl
  //
  GAME_INLINE LatencyBudgetQosPolicy_Impl::LatencyBudgetQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LatencyBudgetQosPolicy_Impl
  //
  GAME_INLINE LatencyBudgetQosPolicy_Impl::~LatencyBudgetQosPolicy_Impl (void)
  {
  }

  //
  // duration
  //
  GAME_INLINE void LatencyBudgetQosPolicy_Impl::duration (double val)
  {
    static const std::string attr_name ("duration");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // duration
  //
  GAME_INLINE double LatencyBudgetQosPolicy_Impl::duration (void) const
  {
    static const std::string attr_name ("duration");
    return this->attribute (attr_name)->double_value ();
  }
}

