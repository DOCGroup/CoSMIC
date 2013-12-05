// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentInstance_Impl
  //
  GAME_INLINE ComponentInstance_Impl::ComponentInstance_Impl (void)
  {
  }

  //
  // ComponentInstance_Impl
  //
  GAME_INLINE ComponentInstance_Impl::ComponentInstance_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInstance_Impl
  //
  GAME_INLINE ComponentInstance_Impl::~ComponentInstance_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void ComponentInstance_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string ComponentInstance_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }
}

