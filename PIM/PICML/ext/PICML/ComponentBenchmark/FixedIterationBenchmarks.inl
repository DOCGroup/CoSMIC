// -*- C++ -*-
namespace PICML
{
  //
  // FixedIterationBenchmarks_Impl
  //
  GAME_INLINE FixedIterationBenchmarks_Impl::FixedIterationBenchmarks_Impl (void)
  {
  }

  //
  // FixedIterationBenchmarks_Impl
  //
  GAME_INLINE FixedIterationBenchmarks_Impl::FixedIterationBenchmarks_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FixedIterationBenchmarks_Impl
  //
  GAME_INLINE FixedIterationBenchmarks_Impl::~FixedIterationBenchmarks_Impl (void)
  {
  }

  //
  // benchmarkIterations
  //
  GAME_INLINE void FixedIterationBenchmarks_Impl::benchmarkIterations (long val)
  {
    static const std::string attr_name ("benchmarkIterations");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // benchmarkIterations
  //
  GAME_INLINE long FixedIterationBenchmarks_Impl::benchmarkIterations (void) const
  {
    static const std::string attr_name ("benchmarkIterations");
    return this->attribute (attr_name)->int_value ();
  }
}

