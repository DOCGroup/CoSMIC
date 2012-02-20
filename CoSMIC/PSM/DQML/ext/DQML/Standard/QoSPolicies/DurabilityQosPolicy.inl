// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // DurabilityQosPolicy_Impl
  //
  GAME_INLINE DurabilityQosPolicy_Impl::DurabilityQosPolicy_Impl (void)
  {
  }

  //
  // DurabilityQosPolicy_Impl
  //
  GAME_INLINE DurabilityQosPolicy_Impl::DurabilityQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DurabilityQosPolicy_Impl
  //
  GAME_INLINE DurabilityQosPolicy_Impl::~DurabilityQosPolicy_Impl (void)
  {
  }

  //
  // kind
  //
  GAME_INLINE void DurabilityQosPolicy_Impl::kind (const std::string & val)
  {
    static const std::string attr_name ("kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // kind
  //
  GAME_INLINE std::string DurabilityQosPolicy_Impl::kind (void) const
  {
    static const std::string attr_name ("kind");
    return this->attribute (attr_name)->string_value ();
  }
}

