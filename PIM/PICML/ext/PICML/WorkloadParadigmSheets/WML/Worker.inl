// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Worker_Impl
  //
  GAME_INLINE Worker_Impl::Worker_Impl (void)
  {
  }

  //
  // Worker_Impl
  //
  GAME_INLINE Worker_Impl::Worker_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Worker_Impl
  //
  GAME_INLINE Worker_Impl::~Worker_Impl (void)
  {
  }

  //
  // Abstract
  //
  GAME_INLINE void Worker_Impl::Abstract (bool val)
  {
    static const std::string attr_name ("Abstract");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // Abstract
  //
  GAME_INLINE bool Worker_Impl::Abstract (void) const
  {
    static const std::string attr_name ("Abstract");
    return this->attribute (attr_name)->bool_value ();
  }
}

