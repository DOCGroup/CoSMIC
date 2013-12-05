// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Interconnect_Impl
  //
  GAME_INLINE Interconnect_Impl::Interconnect_Impl (void)
  {
  }

  //
  // Interconnect_Impl
  //
  GAME_INLINE Interconnect_Impl::Interconnect_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Interconnect_Impl
  //
  GAME_INLINE Interconnect_Impl::~Interconnect_Impl (void)
  {
  }

  //
  // label
  //
  GAME_INLINE void Interconnect_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string Interconnect_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

