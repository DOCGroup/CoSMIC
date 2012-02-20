// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // GroupDataQosPolicy_Impl
  //
  GAME_INLINE GroupDataQosPolicy_Impl::GroupDataQosPolicy_Impl (void)
  {
  }

  //
  // GroupDataQosPolicy_Impl
  //
  GAME_INLINE GroupDataQosPolicy_Impl::GroupDataQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GroupDataQosPolicy_Impl
  //
  GAME_INLINE GroupDataQosPolicy_Impl::~GroupDataQosPolicy_Impl (void)
  {
  }

  //
  // datavalue
  //
  GAME_INLINE void GroupDataQosPolicy_Impl::datavalue (const std::string & val)
  {
    static const std::string attr_name ("datavalue");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // datavalue
  //
  GAME_INLINE std::string GroupDataQosPolicy_Impl::datavalue (void) const
  {
    static const std::string attr_name ("datavalue");
    return this->attribute (attr_name)->string_value ();
  }
}

