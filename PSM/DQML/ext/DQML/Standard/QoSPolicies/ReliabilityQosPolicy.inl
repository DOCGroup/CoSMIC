// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // ReliabilityQosPolicy_Impl
  //
  GAME_INLINE ReliabilityQosPolicy_Impl::ReliabilityQosPolicy_Impl (void)
  {
  }

  //
  // ReliabilityQosPolicy_Impl
  //
  GAME_INLINE ReliabilityQosPolicy_Impl::ReliabilityQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReliabilityQosPolicy_Impl
  //
  GAME_INLINE ReliabilityQosPolicy_Impl::~ReliabilityQosPolicy_Impl (void)
  {
  }

  //
  // reliability_kind
  //
  GAME_INLINE void ReliabilityQosPolicy_Impl::reliability_kind (const std::string & val)
  {
    static const std::string attr_name ("reliability_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // reliability_kind
  //
  GAME_INLINE std::string ReliabilityQosPolicy_Impl::reliability_kind (void) const
  {
    static const std::string attr_name ("reliability_kind");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // max_blocking_time
  //
  GAME_INLINE void ReliabilityQosPolicy_Impl::max_blocking_time (double val)
  {
    static const std::string attr_name ("max_blocking_time");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // max_blocking_time
  //
  GAME_INLINE double ReliabilityQosPolicy_Impl::max_blocking_time (void) const
  {
    static const std::string attr_name ("max_blocking_time");
    return this->attribute (attr_name)->double_value ();
  }

  //
  // synchronous
  //
  GAME_INLINE void ReliabilityQosPolicy_Impl::synchronous (bool val)
  {
    static const std::string attr_name ("synchronous");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // synchronous
  //
  GAME_INLINE bool ReliabilityQosPolicy_Impl::synchronous (void) const
  {
    static const std::string attr_name ("synchronous");
    return this->attribute (attr_name)->bool_value ();
  }
}

