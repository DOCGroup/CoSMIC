// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Variable_Impl
  //
  GAME_INLINE Variable_Impl::Variable_Impl (void)
  {
  }

  //
  // Variable_Impl
  //
  GAME_INLINE Variable_Impl::Variable_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Variable_Impl
  //
  GAME_INLINE Variable_Impl::~Variable_Impl (void)
  {
  }

  //
  // InitialValue
  //
  GAME_INLINE void Variable_Impl::InitialValue (const std::string & val)
  {
    static const std::string attr_name ("InitialValue");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // InitialValue
  //
  GAME_INLINE std::string Variable_Impl::InitialValue (void) const
  {
    static const std::string attr_name ("InitialValue");
    return this->attribute (attr_name)->string_value ();
  }
}

