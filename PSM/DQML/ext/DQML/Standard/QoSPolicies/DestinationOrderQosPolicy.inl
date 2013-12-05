// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // DestinationOrderQosPolicy_Impl
  //
  GAME_INLINE DestinationOrderQosPolicy_Impl::DestinationOrderQosPolicy_Impl (void)
  {
  }

  //
  // DestinationOrderQosPolicy_Impl
  //
  GAME_INLINE DestinationOrderQosPolicy_Impl::DestinationOrderQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DestinationOrderQosPolicy_Impl
  //
  GAME_INLINE DestinationOrderQosPolicy_Impl::~DestinationOrderQosPolicy_Impl (void)
  {
  }

  //
  // dest_order_kind
  //
  GAME_INLINE void DestinationOrderQosPolicy_Impl::dest_order_kind (const std::string & val)
  {
    static const std::string attr_name ("dest_order_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // dest_order_kind
  //
  GAME_INLINE std::string DestinationOrderQosPolicy_Impl::dest_order_kind (void) const
  {
    static const std::string attr_name ("dest_order_kind");
    return this->attribute (attr_name)->string_value ();
  }
}

