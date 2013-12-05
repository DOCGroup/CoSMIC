// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // OwnershipQosPolicy_Impl
  //
  GAME_INLINE OwnershipQosPolicy_Impl::OwnershipQosPolicy_Impl (void)
  {
  }

  //
  // OwnershipQosPolicy_Impl
  //
  GAME_INLINE OwnershipQosPolicy_Impl::OwnershipQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OwnershipQosPolicy_Impl
  //
  GAME_INLINE OwnershipQosPolicy_Impl::~OwnershipQosPolicy_Impl (void)
  {
  }

  //
  // ownership_kind
  //
  GAME_INLINE void OwnershipQosPolicy_Impl::ownership_kind (const std::string & val)
  {
    static const std::string attr_name ("ownership_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // ownership_kind
  //
  GAME_INLINE std::string OwnershipQosPolicy_Impl::ownership_kind (void) const
  {
    static const std::string attr_name ("ownership_kind");
    return this->attribute (attr_name)->string_value ();
  }
}

