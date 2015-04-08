// -*- C++ -*-
namespace DQML
{
  //
  // QoSPolicy_Impl
  //
  GAME_INLINE QoSPolicy_Impl::QoSPolicy_Impl (void)
  {
  }

  //
  // QoSPolicy_Impl
  //
  GAME_INLINE QoSPolicy_Impl::QoSPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~QoSPolicy_Impl
  //
  GAME_INLINE QoSPolicy_Impl::~QoSPolicy_Impl (void)
  {
  }

  //
  // name
  //
  GAME_INLINE void QoSPolicy_Impl::name (const std::string & val)
  {
    static const std::string attr_name ("name");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // name
  //
  GAME_INLINE std::string QoSPolicy_Impl::name (void) const
  {
    static const std::string attr_name ("name");
    return this->attribute (attr_name)->string_value ();
  }
}

