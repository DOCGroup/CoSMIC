// -*- C++ -*-
namespace PICML
{
  //
  // EffectBase_Impl
  //
  GAME_INLINE EffectBase_Impl::EffectBase_Impl (void)
  {
  }

  //
  // EffectBase_Impl
  //
  GAME_INLINE EffectBase_Impl::EffectBase_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EffectBase_Impl
  //
  GAME_INLINE EffectBase_Impl::~EffectBase_Impl (void)
  {
  }

  //
  // Postcondition
  //
  GAME_INLINE void EffectBase_Impl::Postcondition (const std::string & val)
  {
    static const std::string attr_name ("Postcondition");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Postcondition
  //
  GAME_INLINE std::string EffectBase_Impl::Postcondition (void) const
  {
    static const std::string attr_name ("Postcondition");
    return this->attribute (attr_name)->string_value ();
  }
}

