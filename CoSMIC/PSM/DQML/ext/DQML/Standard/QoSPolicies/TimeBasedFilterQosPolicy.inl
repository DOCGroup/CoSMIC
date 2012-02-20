// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // TimeBasedFilterQosPolicy_Impl
  //
  GAME_INLINE TimeBasedFilterQosPolicy_Impl::TimeBasedFilterQosPolicy_Impl (void)
  {
  }

  //
  // TimeBasedFilterQosPolicy_Impl
  //
  GAME_INLINE TimeBasedFilterQosPolicy_Impl::TimeBasedFilterQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TimeBasedFilterQosPolicy_Impl
  //
  GAME_INLINE TimeBasedFilterQosPolicy_Impl::~TimeBasedFilterQosPolicy_Impl (void)
  {
  }

  //
  // minimum_separation
  //
  GAME_INLINE void TimeBasedFilterQosPolicy_Impl::minimum_separation (double val)
  {
    static const std::string attr_name ("minimum_separation");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // minimum_separation
  //
  GAME_INLINE double TimeBasedFilterQosPolicy_Impl::minimum_separation (void) const
  {
    static const std::string attr_name ("minimum_separation");
    return this->attribute (attr_name)->double_value ();
  }
}

