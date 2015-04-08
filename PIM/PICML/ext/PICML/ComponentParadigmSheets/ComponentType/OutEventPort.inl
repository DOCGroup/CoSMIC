// -*- C++ -*-
namespace PICML
{
  //
  // OutEventPort_Impl
  //
  GAME_INLINE OutEventPort_Impl::OutEventPort_Impl (void)
  {
  }

  //
  // OutEventPort_Impl
  //
  GAME_INLINE OutEventPort_Impl::OutEventPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutEventPort_Impl
  //
  GAME_INLINE OutEventPort_Impl::~OutEventPort_Impl (void)
  {
  }

  //
  // single_destination
  //
  GAME_INLINE void OutEventPort_Impl::single_destination (bool val)
  {
    static const std::string attr_name ("single_destination");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // single_destination
  //
  GAME_INLINE bool OutEventPort_Impl::single_destination (void) const
  {
    static const std::string attr_name ("single_destination");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // out_event_port_type
  //
  GAME_INLINE void OutEventPort_Impl::out_event_port_type (const std::string & val)
  {
    static const std::string attr_name ("out_event_port_type");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // out_event_port_type
  //
  GAME_INLINE std::string OutEventPort_Impl::out_event_port_type (void) const
  {
    static const std::string attr_name ("out_event_port_type");
    return this->attribute (attr_name)->string_value ();
  }
}

