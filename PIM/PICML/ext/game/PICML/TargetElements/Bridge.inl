// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Bridge_Impl
  //
  GAME_INLINE Bridge_Impl::Bridge_Impl (void)
  {
  }

  //
  // Bridge_Impl
  //
  GAME_INLINE Bridge_Impl::Bridge_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Bridge_Impl
  //
  GAME_INLINE Bridge_Impl::~Bridge_Impl (void)
  {
  }

  //
  // label
  //
  GAME_INLINE void Bridge_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string Bridge_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }
}

