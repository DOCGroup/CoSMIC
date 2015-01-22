// $Id$

#include "StdAfx.h"
#include "FixedIterationBenchmarks.h"

#if !defined (__GAME_INLINE__)
#include "FixedIterationBenchmarks.inl"
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
  const std::string FixedIterationBenchmarks_Impl::metaname ("FixedIterationBenchmarks");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  FixedIterationBenchmarks FixedIterationBenchmarks_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < FixedIterationBenchmarks > (parent, FixedIterationBenchmarks_Impl::metaname);
  }

  //
  // accept
  //
  void FixedIterationBenchmarks_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_FixedIterationBenchmarks (this);
    else
      v->visit_Atom (this);
  }
}

