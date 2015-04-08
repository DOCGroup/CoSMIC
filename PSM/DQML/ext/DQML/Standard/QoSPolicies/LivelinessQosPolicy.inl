// -*- C++ -*-
namespace DQML
{
  //
  // LivelinessQosPolicy_Impl
  //
  GAME_INLINE LivelinessQosPolicy_Impl::LivelinessQosPolicy_Impl (void)
  {
  }

  //
  // LivelinessQosPolicy_Impl
  //
  GAME_INLINE LivelinessQosPolicy_Impl::LivelinessQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LivelinessQosPolicy_Impl
  //
  GAME_INLINE LivelinessQosPolicy_Impl::~LivelinessQosPolicy_Impl (void)
  {
  }

  //
  // lease_duration
  //
  GAME_INLINE void LivelinessQosPolicy_Impl::lease_duration (double val)
  {
    static const std::string attr_name ("lease_duration");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // lease_duration
  //
  GAME_INLINE double LivelinessQosPolicy_Impl::lease_duration (void) const
  {
    static const std::string attr_name ("lease_duration");
    return this->attribute (attr_name)->double_value ();
  }

  //
  // liveliness_kind
  //
  GAME_INLINE void LivelinessQosPolicy_Impl::liveliness_kind (const std::string & val)
  {
    static const std::string attr_name ("liveliness_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // liveliness_kind
  //
  GAME_INLINE std::string LivelinessQosPolicy_Impl::liveliness_kind (void) const
  {
    static const std::string attr_name ("liveliness_kind");
    return this->attribute (attr_name)->string_value ();
  }
}

