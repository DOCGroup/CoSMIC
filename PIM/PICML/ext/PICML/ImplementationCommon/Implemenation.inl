// -*- C++ -*-
namespace PICML
{
  //
  // Implemenation_Impl
  //
  GAME_INLINE Implemenation_Impl::Implemenation_Impl (void)
  {
  }

  //
  // Implemenation_Impl
  //
  GAME_INLINE Implemenation_Impl::Implemenation_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Implemenation_Impl
  //
  GAME_INLINE Implemenation_Impl::~Implemenation_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void Implemenation_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string Implemenation_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void Implemenation_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string Implemenation_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

