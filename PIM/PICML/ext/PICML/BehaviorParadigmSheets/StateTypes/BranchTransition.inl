// -*- C++ -*-
namespace PICML
{
  //
  // BranchTransition_Impl
  //
  GAME_INLINE BranchTransition_Impl::BranchTransition_Impl (void)
  {
  }

  //
  // BranchTransition_Impl
  //
  GAME_INLINE BranchTransition_Impl::BranchTransition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BranchTransition_Impl
  //
  GAME_INLINE BranchTransition_Impl::~BranchTransition_Impl (void)
  {
  }

  //
  // Condition
  //
  GAME_INLINE void BranchTransition_Impl::Condition (const std::string & val)
  {
    static const std::string attr_name ("Condition");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Condition
  //
  GAME_INLINE std::string BranchTransition_Impl::Condition (void) const
  {
    static const std::string attr_name ("Condition");
    return this->attribute (attr_name)->string_value ();
  }
}

