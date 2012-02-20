// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // TransportPriorityQosPolicy_Impl
  //
  GAME_INLINE TransportPriorityQosPolicy_Impl::TransportPriorityQosPolicy_Impl (void)
  {
  }

  //
  // TransportPriorityQosPolicy_Impl
  //
  GAME_INLINE TransportPriorityQosPolicy_Impl::TransportPriorityQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TransportPriorityQosPolicy_Impl
  //
  GAME_INLINE TransportPriorityQosPolicy_Impl::~TransportPriorityQosPolicy_Impl (void)
  {
  }

  //
  // transport_value
  //
  GAME_INLINE void TransportPriorityQosPolicy_Impl::transport_value (long val)
  {
    static const std::string attr_name ("transport_value");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // transport_value
  //
  GAME_INLINE long TransportPriorityQosPolicy_Impl::transport_value (void) const
  {
    static const std::string attr_name ("transport_value");
    return this->attribute (attr_name)->int_value ();
  }
}

