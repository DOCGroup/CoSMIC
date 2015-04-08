// -*- C++ -*-
namespace PICML
{
  //
  // Taggable_Impl
  //
  GAME_INLINE Taggable_Impl::Taggable_Impl (void)
  {
  }

  //
  // Taggable_Impl
  //
  GAME_INLINE Taggable_Impl::Taggable_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Taggable_Impl
  //
  GAME_INLINE Taggable_Impl::~Taggable_Impl (void)
  {
  }

  //
  // VersionTag
  //
  GAME_INLINE void Taggable_Impl::VersionTag (const std::string & val)
  {
    static const std::string attr_name ("VersionTag");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // VersionTag
  //
  GAME_INLINE std::string Taggable_Impl::VersionTag (void) const
  {
    static const std::string attr_name ("VersionTag");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // SpecifyIdTag
  //
  GAME_INLINE void Taggable_Impl::SpecifyIdTag (const std::string & val)
  {
    static const std::string attr_name ("SpecifyIdTag");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // SpecifyIdTag
  //
  GAME_INLINE std::string Taggable_Impl::SpecifyIdTag (void) const
  {
    static const std::string attr_name ("SpecifyIdTag");
    return this->attribute (attr_name)->string_value ();
  }
}

