// -*- C++ -*-
namespace DQML
{
  //
  // DeadlineQosPolicy_Impl
  //
  GAME_INLINE DeadlineQosPolicy_Impl::DeadlineQosPolicy_Impl (void)
  {
  }

  //
  // DeadlineQosPolicy_Impl
  //
  GAME_INLINE DeadlineQosPolicy_Impl::DeadlineQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DeadlineQosPolicy_Impl
  //
  GAME_INLINE DeadlineQosPolicy_Impl::~DeadlineQosPolicy_Impl (void)
  {
  }

  //
  // period
  //
  GAME_INLINE void DeadlineQosPolicy_Impl::period (double val)
  {
    static const std::string attr_name ("period");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // period
  //
  GAME_INLINE double DeadlineQosPolicy_Impl::period (void) const
  {
    static const std::string attr_name ("period");
    return this->attribute (attr_name)->double_value ();
  }
}

