// -*- C++ -*-
namespace PICML
{
  //
  // RequiredRequestPort_Impl
  //
  GAME_INLINE RequiredRequestPort_Impl::RequiredRequestPort_Impl (void)
  {
  }

  //
  // RequiredRequestPort_Impl
  //
  GAME_INLINE RequiredRequestPort_Impl::RequiredRequestPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequiredRequestPort_Impl
  //
  GAME_INLINE RequiredRequestPort_Impl::~RequiredRequestPort_Impl (void)
  {
  }

  //
  // multiple_connections
  //
  GAME_INLINE void RequiredRequestPort_Impl::multiple_connections (bool val)
  {
    static const std::string attr_name ("multiple_connections");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // multiple_connections
  //
  GAME_INLINE bool RequiredRequestPort_Impl::multiple_connections (void) const
  {
    static const std::string attr_name ("multiple_connections");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // AsyncCommunication
  //
  GAME_INLINE void RequiredRequestPort_Impl::AsyncCommunication (bool val)
  {
    static const std::string attr_name ("AsyncCommunication");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // AsyncCommunication
  //
  GAME_INLINE bool RequiredRequestPort_Impl::AsyncCommunication (void) const
  {
    static const std::string attr_name ("AsyncCommunication");
    return this->attribute (attr_name)->bool_value ();
  }
}

