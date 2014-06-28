// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // ShareQosPolicy_Impl
  //
  GAME_INLINE ShareQosPolicy_Impl::ShareQosPolicy_Impl (void)
  {
  }

  //
  // ShareQosPolicy_Impl
  //
  GAME_INLINE ShareQosPolicy_Impl::ShareQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ShareQosPolicy_Impl
  //
  GAME_INLINE ShareQosPolicy_Impl::~ShareQosPolicy_Impl (void)
  {
  }

  //
  // share_qos_enable
  //
  GAME_INLINE void ShareQosPolicy_Impl::share_qos_enable (bool val)
  {
    static const std::string attr_name ("share_qos_enable");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // share_qos_enable
  //
  GAME_INLINE bool ShareQosPolicy_Impl::share_qos_enable (void) const
  {
    static const std::string attr_name ("share_qos_enable");
    return this->attribute (attr_name)->bool_value ();
  }
}

