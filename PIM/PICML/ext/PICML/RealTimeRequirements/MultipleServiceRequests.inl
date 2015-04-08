// -*- C++ -*-
namespace PICML
{
  //
  // MultipleServiceRequests_Impl
  //
  GAME_INLINE MultipleServiceRequests_Impl::MultipleServiceRequests_Impl (void)
  {
  }

  //
  // MultipleServiceRequests_Impl
  //
  GAME_INLINE MultipleServiceRequests_Impl::MultipleServiceRequests_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MultipleServiceRequests_Impl
  //
  GAME_INLINE MultipleServiceRequests_Impl::~MultipleServiceRequests_Impl (void)
  {
  }

  //
  // maximum_simultaneous_service_level
  //
  GAME_INLINE void MultipleServiceRequests_Impl::maximum_simultaneous_service_level (long val)
  {
    static const std::string attr_name ("maximum_simultaneous_service_level");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // maximum_simultaneous_service_level
  //
  GAME_INLINE long MultipleServiceRequests_Impl::maximum_simultaneous_service_level (void) const
  {
    static const std::string attr_name ("maximum_simultaneous_service_level");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // minimum_simultaneous_service_level
  //
  GAME_INLINE void MultipleServiceRequests_Impl::minimum_simultaneous_service_level (long val)
  {
    static const std::string attr_name ("minimum_simultaneous_service_level");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // minimum_simultaneous_service_level
  //
  GAME_INLINE long MultipleServiceRequests_Impl::minimum_simultaneous_service_level (void) const
  {
    static const std::string attr_name ("minimum_simultaneous_service_level");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // simultaneous_service_execution
  //
  GAME_INLINE void MultipleServiceRequests_Impl::simultaneous_service_execution (bool val)
  {
    static const std::string attr_name ("simultaneous_service_execution");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // simultaneous_service_execution
  //
  GAME_INLINE bool MultipleServiceRequests_Impl::simultaneous_service_execution (void) const
  {
    static const std::string attr_name ("simultaneous_service_execution");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // buffer_service_requests
  //
  GAME_INLINE void MultipleServiceRequests_Impl::buffer_service_requests (bool val)
  {
    static const std::string attr_name ("buffer_service_requests");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // buffer_service_requests
  //
  GAME_INLINE bool MultipleServiceRequests_Impl::buffer_service_requests (void) const
  {
    static const std::string attr_name ("buffer_service_requests");
    return this->attribute (attr_name)->bool_value ();
  }
}

