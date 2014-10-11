// $Id$

#include "StdAfx.h"
#include "BenchmarkType.h"

#if !defined (__GAME_INLINE__)
#include "BenchmarkType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkType_Impl::metaname ("BenchmarkType");

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis BenchmarkType_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // src_BenchmarkCharacteristics
  //
  size_t BenchmarkType_Impl::src_BenchmarkCharacteristics (std::vector <BenchmarkCharacteristics> & items) const
  {
    return this->in_connections <BenchmarkCharacteristics> (items);
  }
}

