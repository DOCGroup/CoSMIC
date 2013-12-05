// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // PeriodicEvent_Impl
  //
  GAME_INLINE PeriodicEvent_Impl::PeriodicEvent_Impl (void)
  {
  }

  //
  // PeriodicEvent_Impl
  //
  GAME_INLINE PeriodicEvent_Impl::PeriodicEvent_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PeriodicEvent_Impl
  //
  GAME_INLINE PeriodicEvent_Impl::~PeriodicEvent_Impl (void)
  {
  }

  //
  // Hertz
  //
  GAME_INLINE void PeriodicEvent_Impl::Hertz (const std::string & val)
  {
    static const std::string attr_name ("Hertz");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Hertz
  //
  GAME_INLINE std::string PeriodicEvent_Impl::Hertz (void) const
  {
    static const std::string attr_name ("Hertz");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // Distribution
  //
  GAME_INLINE void PeriodicEvent_Impl::Distribution (const std::string & val)
  {
    static const std::string attr_name ("Distribution");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Distribution
  //
  GAME_INLINE std::string PeriodicEvent_Impl::Distribution (void) const
  {
    static const std::string attr_name ("Distribution");
    return this->attribute (attr_name)->string_value ();
  }
}

