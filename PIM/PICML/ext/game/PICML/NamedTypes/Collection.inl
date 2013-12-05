// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Collection_Impl
  //
  GAME_INLINE Collection_Impl::Collection_Impl (void)
  {
  }

  //
  // Collection_Impl
  //
  GAME_INLINE Collection_Impl::Collection_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Collection_Impl
  //
  GAME_INLINE Collection_Impl::~Collection_Impl (void)
  {
  }

  //
  // bound
  //
  GAME_INLINE void Collection_Impl::bound (const std::string & val)
  {
    static const std::string attr_name ("bound");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // bound
  //
  GAME_INLINE std::string Collection_Impl::bound (void) const
  {
    static const std::string attr_name ("bound");
    return this->attribute (attr_name)->string_value ();
  }
}

