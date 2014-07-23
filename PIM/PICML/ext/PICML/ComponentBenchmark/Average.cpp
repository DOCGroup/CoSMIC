// $Id$

#include "StdAfx.h"
#include "Average.h"

#if !defined (__GAME_INLINE__)
#include "Average.inl"
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
  const std::string Average_Impl::metaname ("Average");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Average Average_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < Average > (parent, Average_Impl::metaname);
  }

  //
  // _create (const MetricsBase_in)
  //
  Average Average_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create_object < Average > (parent, Average_Impl::metaname);
  }

  //
  // accept
  //
  void Average_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Average (this);
    else
      v->visit_Atom (this);
  }
}

