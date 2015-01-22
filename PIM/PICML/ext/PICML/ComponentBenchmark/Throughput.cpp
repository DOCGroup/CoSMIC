// $Id$

#include "StdAfx.h"
#include "Throughput.h"

#if !defined (__GAME_INLINE__)
#include "Throughput.inl"
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
  const std::string Throughput_Impl::metaname ("Throughput");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Throughput Throughput_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < Throughput > (parent, Throughput_Impl::metaname);
  }

  //
  // accept
  //
  void Throughput_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Throughput (this);
    else
      v->visit_Model (this);
  }
}

