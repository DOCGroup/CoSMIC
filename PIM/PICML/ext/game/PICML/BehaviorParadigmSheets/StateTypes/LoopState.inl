// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // LoopState_Impl
  //
  GAME_INLINE LoopState_Impl::LoopState_Impl (void)
  {
  }

  //
  // LoopState_Impl
  //
  GAME_INLINE LoopState_Impl::LoopState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LoopState_Impl
  //
  GAME_INLINE LoopState_Impl::~LoopState_Impl (void)
  {
  }

  //
  // LoopingCondition
  //
  GAME_INLINE void LoopState_Impl::LoopingCondition (const std::string & val)
  {
    static const std::string attr_name ("LoopingCondition");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // LoopingCondition
  //
  GAME_INLINE std::string LoopState_Impl::LoopingCondition (void) const
  {
    static const std::string attr_name ("LoopingCondition");
    return this->attribute (attr_name)->string_value ();
  }
}

