// -*- C++ -*-
namespace DQML
{
  //
  // OwnershipStrengthQosPolicy_Impl
  //
  GAME_INLINE OwnershipStrengthQosPolicy_Impl::OwnershipStrengthQosPolicy_Impl (void)
  {
  }

  //
  // OwnershipStrengthQosPolicy_Impl
  //
  GAME_INLINE OwnershipStrengthQosPolicy_Impl::OwnershipStrengthQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OwnershipStrengthQosPolicy_Impl
  //
  GAME_INLINE OwnershipStrengthQosPolicy_Impl::~OwnershipStrengthQosPolicy_Impl (void)
  {
  }

  //
  // ownership_value
  //
  GAME_INLINE void OwnershipStrengthQosPolicy_Impl::ownership_value (long val)
  {
    static const std::string attr_name ("ownership_value");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // ownership_value
  //
  GAME_INLINE long OwnershipStrengthQosPolicy_Impl::ownership_value (void) const
  {
    static const std::string attr_name ("ownership_value");
    return this->attribute (attr_name)->int_value ();
  }
}

