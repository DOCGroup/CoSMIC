// -*- C++ -*-
namespace PICML
{
  //
  // ECRole_Impl
  //
  GAME_INLINE ECRole_Impl::ECRole_Impl (void)
  {
  }

  //
  // ECRole_Impl
  //
  GAME_INLINE ECRole_Impl::ECRole_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ECRole_Impl
  //
  GAME_INLINE ECRole_Impl::~ECRole_Impl (void)
  {
  }

  //
  // ECFilterType
  //
  GAME_INLINE void ECRole_Impl::ECFilterType (const std::string & val)
  {
    static const std::string attr_name ("ECFilterType");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // ECFilterType
  //
  GAME_INLINE std::string ECRole_Impl::ECFilterType (void) const
  {
    static const std::string attr_name ("ECFilterType");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // rolekind
  //
  GAME_INLINE void ECRole_Impl::rolekind (const std::string & val)
  {
    static const std::string attr_name ("rolekind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // rolekind
  //
  GAME_INLINE std::string ECRole_Impl::rolekind (void) const
  {
    static const std::string attr_name ("rolekind");
    return this->attribute (attr_name)->string_value ();
  }
}

