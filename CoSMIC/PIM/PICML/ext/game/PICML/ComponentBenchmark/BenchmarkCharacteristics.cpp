// $Id$

#include "StdAfx.h"
#include "BenchmarkCharacteristics.h"

#if !defined (__GAME_INLINE__)
#include "BenchmarkCharacteristics.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkCharacteristics_Impl::metaname ("BenchmarkCharacteristics");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  BenchmarkCharacteristics BenchmarkCharacteristics_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < BenchmarkCharacteristics > (parent, BenchmarkCharacteristics_Impl::metaname);
  }

  //
  // accept
  //
  void BenchmarkCharacteristics_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_BenchmarkCharacteristics (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // BenchmarkType
  //
  BenchmarkType BenchmarkCharacteristics_Impl::src_BenchmarkType (void) const
  {
    return BenchmarkType::_narrow (this->src ());
  }

  //
  // MetricsBase
  //
  MetricsBase BenchmarkCharacteristics_Impl::dst_MetricsBase (void) const
  {
    return MetricsBase::_narrow (this->dst ());
  }
}

