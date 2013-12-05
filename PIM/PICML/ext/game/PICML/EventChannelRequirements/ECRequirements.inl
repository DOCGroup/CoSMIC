// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ECRequirements_Impl
  //
  GAME_INLINE ECRequirements_Impl::ECRequirements_Impl (void)
  {
  }

  //
  // ECRequirements_Impl
  //
  GAME_INLINE ECRequirements_Impl::ECRequirements_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ECRequirements_Impl
  //
  GAME_INLINE ECRequirements_Impl::~ECRequirements_Impl (void)
  {
  }

  //
  // ConfigureRTQoS
  //
  GAME_INLINE void ECRequirements_Impl::ConfigureRTQoS (bool val)
  {
    static const std::string attr_name ("ConfigureRTQoS");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // ConfigureRTQoS
  //
  GAME_INLINE bool ECRequirements_Impl::ConfigureRTQoS (void) const
  {
    static const std::string attr_name ("ConfigureRTQoS");
    return this->attribute (attr_name)->bool_value ();
  }
}

