// $Id$

#include "stdafx.h"
#include "BenchmarkType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkType_Impl::metaname = "BenchmarkType";

  //
  // BenchmarkType_Impl
  //
  BenchmarkType_Impl::BenchmarkType_Impl (void)
  {
  }

  //
  // BenchmarkType_Impl
  //
  BenchmarkType_Impl::BenchmarkType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BenchmarkType_Impl
  //
  BenchmarkType_Impl::~BenchmarkType_Impl (void)
  {
  }

  //
  // in_BenchmarkCharacteristics_connections
  //
  size_t BenchmarkType_Impl::in_BenchmarkCharacteristics_connections (std::vector <BenchmarkCharacteristics> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis BenchmarkType_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

