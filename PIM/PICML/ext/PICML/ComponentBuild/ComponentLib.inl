// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ComponentLib_Impl
  //
  GAME_INLINE ComponentLib_Impl::ComponentLib_Impl (void)
  {
  }

  //
  // ComponentLib_Impl
  //
  GAME_INLINE ComponentLib_Impl::ComponentLib_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentLib_Impl
  //
  GAME_INLINE ComponentLib_Impl::~ComponentLib_Impl (void)
  {
  }

  //
  // libraryexport
  //
  GAME_INLINE void ComponentLib_Impl::libraryexport (const std::string & val)
  {
    static const std::string attr_name ("libraryexport");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // libraryexport
  //
  GAME_INLINE std::string ComponentLib_Impl::libraryexport (void) const
  {
    static const std::string attr_name ("libraryexport");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // sharedname
  //
  GAME_INLINE void ComponentLib_Impl::sharedname (const std::string & val)
  {
    static const std::string attr_name ("sharedname");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // sharedname
  //
  GAME_INLINE std::string ComponentLib_Impl::sharedname (void) const
  {
    static const std::string attr_name ("sharedname");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // ORBServices
  //
  GAME_INLINE void ComponentLib_Impl::ORBServices (const std::string & val)
  {
    static const std::string attr_name ("ORBServices");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // ORBServices
  //
  GAME_INLINE std::string ComponentLib_Impl::ORBServices (void) const
  {
    static const std::string attr_name ("ORBServices");
    return this->attribute (attr_name)->string_value ();
  }
}

