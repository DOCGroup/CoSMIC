// -*- C++ -*-
namespace DQML
{
  //
  // SubscriptionKeyQosPolicy_Impl
  //
  GAME_INLINE SubscriptionKeyQosPolicy_Impl::SubscriptionKeyQosPolicy_Impl (void)
  {
  }

  //
  // SubscriptionKeyQosPolicy_Impl
  //
  GAME_INLINE SubscriptionKeyQosPolicy_Impl::SubscriptionKeyQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SubscriptionKeyQosPolicy_Impl
  //
  GAME_INLINE SubscriptionKeyQosPolicy_Impl::~SubscriptionKeyQosPolicy_Impl (void)
  {
  }

  //
  // key_list
  //
  GAME_INLINE void SubscriptionKeyQosPolicy_Impl::key_list (const std::string & val)
  {
    static const std::string attr_name ("key_list");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // key_list
  //
  GAME_INLINE std::string SubscriptionKeyQosPolicy_Impl::key_list (void) const
  {
    static const std::string attr_name ("key_list");
    return this->attribute (attr_name)->string_value ();
  }
}

