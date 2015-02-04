// $Id$

#include "StdAfx.h"
#include "TriggerBenchmarks.h"

#if !defined (__GAME_INLINE__)
#include "TriggerBenchmarks.inl"
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
  const std::string TriggerBenchmarks_Impl::metaname ("TriggerBenchmarks");

  //
  // is_abstract
  //
  const bool TriggerBenchmarks_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in)
  //
  TriggerBenchmarks TriggerBenchmarks_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < TriggerBenchmarks > (parent, TriggerBenchmarks_Impl::metaname);
  }

  //
  // accept
  //
  void TriggerBenchmarks_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TriggerBenchmarks (this);
    else
      v->visit_Atom (this);
  }
}

