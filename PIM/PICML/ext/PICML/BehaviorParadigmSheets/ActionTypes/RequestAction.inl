// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // RequestAction_Impl
  //
  GAME_INLINE RequestAction_Impl::RequestAction_Impl (void)
  {
  }

  //
  // RequestAction_Impl
  //
  GAME_INLINE RequestAction_Impl::RequestAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequestAction_Impl
  //
  GAME_INLINE RequestAction_Impl::~RequestAction_Impl (void)
  {
  }

  //
  // MethodName
  //
  GAME_INLINE void RequestAction_Impl::MethodName (const std::string & val)
  {
    static const std::string attr_name ("MethodName");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // MethodName
  //
  GAME_INLINE std::string RequestAction_Impl::MethodName (void) const
  {
    static const std::string attr_name ("MethodName");
    return this->attribute (attr_name)->string_value ();
  }
}

