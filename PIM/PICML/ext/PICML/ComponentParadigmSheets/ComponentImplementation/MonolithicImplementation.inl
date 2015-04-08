// -*- C++ -*-
namespace PICML
{
  //
  // MonolithicImplementation_Impl
  //
  GAME_INLINE MonolithicImplementation_Impl::MonolithicImplementation_Impl (void)
  {
  }

  //
  // MonolithicImplementation_Impl
  //
  GAME_INLINE MonolithicImplementation_Impl::MonolithicImplementation_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MonolithicImplementation_Impl
  //
  GAME_INLINE MonolithicImplementation_Impl::~MonolithicImplementation_Impl (void)
  {
  }

  //
  // defaultVersion
  //
  GAME_INLINE void MonolithicImplementation_Impl::defaultVersion (const std::string & val)
  {
    static const std::string attr_name ("defaultVersion");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // defaultVersion
  //
  GAME_INLINE std::string MonolithicImplementation_Impl::defaultVersion (void) const
  {
    static const std::string attr_name ("defaultVersion");
    return this->attribute (attr_name)->string_value ();
  }
}

