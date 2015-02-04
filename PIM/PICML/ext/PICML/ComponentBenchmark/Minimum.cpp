// $Id$

#include "StdAfx.h"
#include "Minimum.h"

#if !defined (__GAME_INLINE__)
#include "Minimum.inl"
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
  const std::string Minimum_Impl::metaname ("Minimum");

  //
  // is_abstract
  //
  const bool Minimum_Impl::is_abstract = false;

  //
  // _create (const MetricsBase_in)
  //
  Minimum Minimum_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create < Minimum > (parent, Minimum_Impl::metaname);
  }

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Minimum Minimum_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < Minimum > (parent, Minimum_Impl::metaname);
  }

  //
  // accept
  //
  void Minimum_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Minimum (this);
    else
      v->visit_Atom (this);
  }
}

