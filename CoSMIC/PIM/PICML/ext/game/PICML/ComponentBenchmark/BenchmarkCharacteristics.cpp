// $Id$

#include "stdafx.h"
#include "BenchmarkCharacteristics.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkCharacteristics_Impl::metaname = "BenchmarkCharacteristics";

  //
  // BenchmarkCharacteristics_Impl
  //
  BenchmarkCharacteristics_Impl::BenchmarkCharacteristics_Impl (void)
  {
  }

  //
  // BenchmarkCharacteristics_Impl
  //
  BenchmarkCharacteristics_Impl::BenchmarkCharacteristics_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BenchmarkCharacteristics_Impl
  //
  BenchmarkCharacteristics_Impl::~BenchmarkCharacteristics_Impl (void)
  {
  }

  //
  // accept
  //
  void BenchmarkCharacteristics_Impl::accept (Visitor * v)
  {
    v->visit_BenchmarkCharacteristics (this);
  }

  //
  // _create
  //
  BenchmarkCharacteristics BenchmarkCharacteristics_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <BenchmarkCharacteristics> (parent, BenchmarkCharacteristics_Impl::metaname);
  }

  //
  // src_BenchmarkType
  //
  BenchmarkType BenchmarkCharacteristics_Impl::src_BenchmarkType (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return BenchmarkType::_narrow (target);
  }

  //
  // dst_MetricsBase
  //
  MetricsBase BenchmarkCharacteristics_Impl::dst_MetricsBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return MetricsBase::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis BenchmarkCharacteristics_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

