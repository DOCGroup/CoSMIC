// -*- C++ -*-
namespace PICML
{
  //
  // ServiceLevels_Impl
  //
  GAME_INLINE ServiceLevels_Impl::ServiceLevels_Impl (void)
  {
  }

  //
  // ServiceLevels_Impl
  //
  GAME_INLINE ServiceLevels_Impl::ServiceLevels_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServiceLevels_Impl
  //
  GAME_INLINE ServiceLevels_Impl::~ServiceLevels_Impl (void)
  {
  }

  //
  // varying_service_levels
  //
  GAME_INLINE void ServiceLevels_Impl::varying_service_levels (bool val)
  {
    static const std::string attr_name ("varying_service_levels");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // varying_service_levels
  //
  GAME_INLINE bool ServiceLevels_Impl::varying_service_levels (void) const
  {
    static const std::string attr_name ("varying_service_levels");
    return this->attribute (attr_name)->bool_value ();
  }
}

