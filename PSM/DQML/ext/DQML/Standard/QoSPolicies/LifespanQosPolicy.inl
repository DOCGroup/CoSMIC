// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // LifespanQosPolicy_Impl
  //
  GAME_INLINE LifespanQosPolicy_Impl::LifespanQosPolicy_Impl (void)
  {
  }

  //
  // LifespanQosPolicy_Impl
  //
  GAME_INLINE LifespanQosPolicy_Impl::LifespanQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LifespanQosPolicy_Impl
  //
  GAME_INLINE LifespanQosPolicy_Impl::~LifespanQosPolicy_Impl (void)
  {
  }

  //
  // lifespan_duration
  //
  GAME_INLINE void LifespanQosPolicy_Impl::lifespan_duration (double val)
  {
    static const std::string attr_name ("lifespan_duration");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // lifespan_duration
  //
  GAME_INLINE double LifespanQosPolicy_Impl::lifespan_duration (void) const
  {
    static const std::string attr_name ("lifespan_duration");
    return this->attribute (attr_name)->double_value ();
  }
}

