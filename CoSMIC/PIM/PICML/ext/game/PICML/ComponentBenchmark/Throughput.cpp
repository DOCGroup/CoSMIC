// $Id$

#include "StdAfx.h"
#include "Throughput.h"

#if !defined (__GAME_INLINE__)
#include "Throughput.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Throughput_Impl::metaname ("Throughput");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Throughput Throughput_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < Throughput > (parent, Throughput_Impl::metaname);
  }

  //
  // _create (const MetricsBase_in)
  //
  Throughput Throughput_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create_object < Throughput > (parent, Throughput_Impl::metaname);
  }

  //
  // accept
  //
  void Throughput_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Throughput (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

