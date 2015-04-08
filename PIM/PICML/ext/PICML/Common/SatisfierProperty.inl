// -*- C++ -*-
namespace PICML
{
  //
  // SatisfierProperty_Impl
  //
  GAME_INLINE SatisfierProperty_Impl::SatisfierProperty_Impl (void)
  {
  }

  //
  // SatisfierProperty_Impl
  //
  GAME_INLINE SatisfierProperty_Impl::SatisfierProperty_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SatisfierProperty_Impl
  //
  GAME_INLINE SatisfierProperty_Impl::~SatisfierProperty_Impl (void)
  {
  }

  //
  // SatisfierPropertyKind
  //
  GAME_INLINE void SatisfierProperty_Impl::SatisfierPropertyKind (const std::string & val)
  {
    static const std::string attr_name ("SatisfierPropertyKind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // SatisfierPropertyKind
  //
  GAME_INLINE std::string SatisfierProperty_Impl::SatisfierPropertyKind (void) const
  {
    static const std::string attr_name ("SatisfierPropertyKind");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // DataValue
  //
  GAME_INLINE void SatisfierProperty_Impl::DataValue (const std::string & val)
  {
    static const std::string attr_name ("DataValue");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // DataValue
  //
  GAME_INLINE std::string SatisfierProperty_Impl::DataValue (void) const
  {
    static const std::string attr_name ("DataValue");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // dynamic
  //
  GAME_INLINE void SatisfierProperty_Impl::dynamic (bool val)
  {
    static const std::string attr_name ("dynamic");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // dynamic
  //
  GAME_INLINE bool SatisfierProperty_Impl::dynamic (void) const
  {
    static const std::string attr_name ("dynamic");
    return this->attribute (attr_name)->bool_value ();
  }
}

