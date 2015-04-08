// -*- C++ -*-
namespace PICML
{
  //
  // Constant_Impl
  //
  GAME_INLINE Constant_Impl::Constant_Impl (void)
  {
  }

  //
  // Constant_Impl
  //
  GAME_INLINE Constant_Impl::Constant_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Constant_Impl
  //
  GAME_INLINE Constant_Impl::~Constant_Impl (void)
  {
  }

  //
  // value
  //
  GAME_INLINE void Constant_Impl::value (const std::string & val)
  {
    static const std::string attr_name ("value");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // value
  //
  GAME_INLINE std::string Constant_Impl::value (void) const
  {
    static const std::string attr_name ("value");
    return this->attribute (attr_name)->string_value ();
  }
}

