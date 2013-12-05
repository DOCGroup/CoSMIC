// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ExternalPort_Impl
  //
  GAME_INLINE ExternalPort_Impl::ExternalPort_Impl (void)
  {
  }

  //
  // ExternalPort_Impl
  //
  GAME_INLINE ExternalPort_Impl::ExternalPort_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExternalPort_Impl
  //
  GAME_INLINE ExternalPort_Impl::~ExternalPort_Impl (void)
  {
  }

  //
  // location
  //
  GAME_INLINE void ExternalPort_Impl::location (const std::string & val)
  {
    static const std::string attr_name ("location");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // location
  //
  GAME_INLINE std::string ExternalPort_Impl::location (void) const
  {
    static const std::string attr_name ("location");
    return this->attribute (attr_name)->string_value ();
  }
}

