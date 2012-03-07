// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // PeriodicBenchmarks_Impl
  //
  GAME_INLINE PeriodicBenchmarks_Impl::PeriodicBenchmarks_Impl (void)
  {
  }

  //
  // PeriodicBenchmarks_Impl
  //
  GAME_INLINE PeriodicBenchmarks_Impl::PeriodicBenchmarks_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PeriodicBenchmarks_Impl
  //
  GAME_INLINE PeriodicBenchmarks_Impl::~PeriodicBenchmarks_Impl (void)
  {
  }

  //
  // timeperiod
  //
  GAME_INLINE void PeriodicBenchmarks_Impl::timeperiod (long val)
  {
    static const std::string attr_name ("timeperiod");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // timeperiod
  //
  GAME_INLINE long PeriodicBenchmarks_Impl::timeperiod (void) const
  {
    static const std::string attr_name ("timeperiod");
    return this->attribute (attr_name)->int_value ();
  }
}

