// $Id$

#include "stdafx.h"
#include "DataAnalysisBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataAnalysisBase_Impl::metaname = "DataAnalysisBase";

  //
  // DataAnalysisBase_Impl
  //
  DataAnalysisBase_Impl::DataAnalysisBase_Impl (void)
  {
  }

  //
  // DataAnalysisBase_Impl
  //
  DataAnalysisBase_Impl::DataAnalysisBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataAnalysisBase_Impl
  //
  DataAnalysisBase_Impl::~DataAnalysisBase_Impl (void)
  {
  }

  //
  // parent_MetricsBase
  //
  MetricsBase DataAnalysisBase_Impl::parent_MetricsBase (void) const
  {
    return ::GAME::Mga::get_parent <MetricsBase> (this->object_.p);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis DataAnalysisBase_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

