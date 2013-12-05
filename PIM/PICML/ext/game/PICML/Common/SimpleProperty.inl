// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // SimpleProperty_Impl
  //
  GAME_INLINE SimpleProperty_Impl::SimpleProperty_Impl (void)
  {
  }

  //
  // SimpleProperty_Impl
  //
  GAME_INLINE SimpleProperty_Impl::SimpleProperty_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SimpleProperty_Impl
  //
  GAME_INLINE SimpleProperty_Impl::~SimpleProperty_Impl (void)
  {
  }

  //
  // Value
  //
  GAME_INLINE void SimpleProperty_Impl::Value (const std::string & val)
  {
    static const std::string attr_name ("Value");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Value
  //
  GAME_INLINE std::string SimpleProperty_Impl::Value (void) const
  {
    static const std::string attr_name ("Value");
    return this->attribute (attr_name)->string_value ();
  }
}

