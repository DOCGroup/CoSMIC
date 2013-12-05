// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // TaskSet_Impl
  //
  GAME_INLINE TaskSet_Impl::TaskSet_Impl (void)
  {
  }

  //
  // TaskSet_Impl
  //
  GAME_INLINE TaskSet_Impl::TaskSet_Impl (IMgaSet * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TaskSet_Impl
  //
  GAME_INLINE TaskSet_Impl::~TaskSet_Impl (void)
  {
  }

  //
  // priority
  //
  GAME_INLINE void TaskSet_Impl::priority (long val)
  {
    static const std::string attr_name ("priority");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // priority
  //
  GAME_INLINE long TaskSet_Impl::priority (void) const
  {
    static const std::string attr_name ("priority");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // rate
  //
  GAME_INLINE void TaskSet_Impl::rate (long val)
  {
    static const std::string attr_name ("rate");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // rate
  //
  GAME_INLINE long TaskSet_Impl::rate (void) const
  {
    static const std::string attr_name ("rate");
    return this->attribute (attr_name)->int_value ();
  }
}

