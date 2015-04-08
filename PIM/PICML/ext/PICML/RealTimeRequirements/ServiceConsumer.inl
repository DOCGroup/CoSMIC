// -*- C++ -*-
namespace PICML
{
  //
  // ServiceConsumer_Impl
  //
  GAME_INLINE ServiceConsumer_Impl::ServiceConsumer_Impl (void)
  {
  }

  //
  // ServiceConsumer_Impl
  //
  GAME_INLINE ServiceConsumer_Impl::ServiceConsumer_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServiceConsumer_Impl
  //
  GAME_INLINE ServiceConsumer_Impl::~ServiceConsumer_Impl (void)
  {
  }

  //
  // prioritize_service_invocations
  //
  GAME_INLINE void ServiceConsumer_Impl::prioritize_service_invocations (bool val)
  {
    static const std::string attr_name ("prioritize_service_invocations");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // prioritize_service_invocations
  //
  GAME_INLINE bool ServiceConsumer_Impl::prioritize_service_invocations (void) const
  {
    static const std::string attr_name ("prioritize_service_invocations");
    return this->attribute (attr_name)->bool_value ();
  }
}

