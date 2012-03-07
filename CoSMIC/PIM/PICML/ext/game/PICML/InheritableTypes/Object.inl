// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Object_Impl
  //
  GAME_INLINE Object_Impl::Object_Impl (void)
  {
  }

  //
  // Object_Impl
  //
  GAME_INLINE Object_Impl::Object_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Object_Impl
  //
  GAME_INLINE Object_Impl::~Object_Impl (void)
  {
  }

  //
  // InterfaceSemantics
  //
  GAME_INLINE void Object_Impl::InterfaceSemantics (const std::string & val)
  {
    static const std::string attr_name ("InterfaceSemantics");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // InterfaceSemantics
  //
  GAME_INLINE std::string Object_Impl::InterfaceSemantics (void) const
  {
    static const std::string attr_name ("InterfaceSemantics");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // SupportsAsync
  //
  GAME_INLINE void Object_Impl::SupportsAsync (bool val)
  {
    static const std::string attr_name ("SupportsAsync");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // SupportsAsync
  //
  GAME_INLINE bool Object_Impl::SupportsAsync (void) const
  {
    static const std::string attr_name ("SupportsAsync");
    return this->attribute (attr_name)->bool_value ();
  }
}

