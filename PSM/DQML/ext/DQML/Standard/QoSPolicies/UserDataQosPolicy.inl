// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // UserDataQosPolicy_Impl
  //
  GAME_INLINE UserDataQosPolicy_Impl::UserDataQosPolicy_Impl (void)
  {
  }

  //
  // UserDataQosPolicy_Impl
  //
  GAME_INLINE UserDataQosPolicy_Impl::UserDataQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~UserDataQosPolicy_Impl
  //
  GAME_INLINE UserDataQosPolicy_Impl::~UserDataQosPolicy_Impl (void)
  {
  }

  //
  // user_value
  //
  GAME_INLINE void UserDataQosPolicy_Impl::user_value (const std::string & val)
  {
    static const std::string attr_name ("user_value");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // user_value
  //
  GAME_INLINE std::string UserDataQosPolicy_Impl::user_value (void) const
  {
    static const std::string attr_name ("user_value");
    return this->attribute (attr_name)->string_value ();
  }
}

