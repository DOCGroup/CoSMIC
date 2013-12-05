// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Domain_Impl
  //
  GAME_INLINE Domain_Impl::Domain_Impl (void)
  {
  }

  //
  // Domain_Impl
  //
  GAME_INLINE Domain_Impl::Domain_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Domain_Impl
  //
  GAME_INLINE Domain_Impl::~Domain_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void Domain_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string Domain_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void Domain_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string Domain_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

