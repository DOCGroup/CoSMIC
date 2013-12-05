// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ActionBase_Impl
  //
  GAME_INLINE ActionBase_Impl::ActionBase_Impl (void)
  {
  }

  //
  // ActionBase_Impl
  //
  GAME_INLINE ActionBase_Impl::ActionBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ActionBase_Impl
  //
  GAME_INLINE ActionBase_Impl::~ActionBase_Impl (void)
  {
  }

  //
  // Duration
  //
  GAME_INLINE void ActionBase_Impl::Duration (long val)
  {
    static const std::string attr_name ("Duration");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // Duration
  //
  GAME_INLINE long ActionBase_Impl::Duration (void) const
  {
    static const std::string attr_name ("Duration");
    return this->attribute (attr_name)->int_value ();
  }
}

