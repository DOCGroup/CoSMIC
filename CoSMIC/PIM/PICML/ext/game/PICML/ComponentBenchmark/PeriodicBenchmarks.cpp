// $Id$

#include "StdAfx.h"
#include "PeriodicBenchmarks.h"

#if !defined (__GAME_INLINE__)
#include "PeriodicBenchmarks.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PeriodicBenchmarks_Impl::metaname ("PeriodicBenchmarks");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  PeriodicBenchmarks PeriodicBenchmarks_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < PeriodicBenchmarks > (parent, PeriodicBenchmarks_Impl::metaname);
  }

  //
  // accept
  //
  void PeriodicBenchmarks_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PeriodicBenchmarks (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

