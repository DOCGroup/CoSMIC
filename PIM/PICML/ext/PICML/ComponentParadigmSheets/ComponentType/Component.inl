// -*- C++ -*-
namespace PICML
{
  //
  // Component_Impl
  //
  GAME_INLINE Component_Impl::Component_Impl (void)
  {
  }

  //
  // Component_Impl
  //
  GAME_INLINE Component_Impl::Component_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Component_Impl
  //
  GAME_INLINE Component_Impl::~Component_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void Component_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string Component_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void Component_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string Component_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

