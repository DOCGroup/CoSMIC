// -*- C++ -*-
namespace PICML
{
  //
  // ServiceProvider_Impl
  //
  GAME_INLINE ServiceProvider_Impl::ServiceProvider_Impl (void)
  {
  }

  //
  // ServiceProvider_Impl
  //
  GAME_INLINE ServiceProvider_Impl::ServiceProvider_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServiceProvider_Impl
  //
  GAME_INLINE ServiceProvider_Impl::~ServiceProvider_Impl (void)
  {
  }

  //
  // fixed_prioirty_service_execution
  //
  GAME_INLINE void ServiceProvider_Impl::fixed_prioirty_service_execution (bool val)
  {
    static const std::string attr_name ("fixed_prioirty_service_execution");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // fixed_prioirty_service_execution
  //
  GAME_INLINE bool ServiceProvider_Impl::fixed_prioirty_service_execution (void) const
  {
    static const std::string attr_name ("fixed_prioirty_service_execution");
    return this->attribute (attr_name)->bool_value ();
  }
}

