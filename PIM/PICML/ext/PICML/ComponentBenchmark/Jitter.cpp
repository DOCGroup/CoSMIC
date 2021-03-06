#include "StdAfx.h"
#include "Jitter.h"

#if !defined (__GAME_INLINE__)
#include "Jitter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Jitter_Impl::metaname ("Jitter");

  //
  // is_abstract
  //
  const bool Jitter_Impl::is_abstract = false;

  //
  // _create (const MetricsBase_in)
  //
  Jitter Jitter_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create < Jitter > (parent, Jitter_Impl::metaname);
  }

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Jitter Jitter_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < Jitter > (parent, Jitter_Impl::metaname);
  }

  //
  // accept
  //
  void Jitter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Jitter (this);
    else
      v->visit_Atom (this);
  }
}

