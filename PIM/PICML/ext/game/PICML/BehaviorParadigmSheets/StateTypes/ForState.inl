// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ForState_Impl
  //
  GAME_INLINE ForState_Impl::ForState_Impl (void)
  {
  }

  //
  // ForState_Impl
  //
  GAME_INLINE ForState_Impl::ForState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ForState_Impl
  //
  GAME_INLINE ForState_Impl::~ForState_Impl (void)
  {
  }

  //
  // InitialCondition
  //
  GAME_INLINE void ForState_Impl::InitialCondition (const std::string & val)
  {
    static const std::string attr_name ("InitialCondition");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // InitialCondition
  //
  GAME_INLINE std::string ForState_Impl::InitialCondition (void) const
  {
    static const std::string attr_name ("InitialCondition");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // IncrementExpr
  //
  GAME_INLINE void ForState_Impl::IncrementExpr (const std::string & val)
  {
    static const std::string attr_name ("IncrementExpr");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // IncrementExpr
  //
  GAME_INLINE std::string ForState_Impl::IncrementExpr (void) const
  {
    static const std::string attr_name ("IncrementExpr");
    return this->attribute (attr_name)->string_value ();
  }
}

