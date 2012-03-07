// $Id$

#include "StdAfx.h"
#include "Minimum.h"

#if !defined (__GAME_INLINE__)
#include "Minimum.inl"
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
  const std::string Minimum_Impl::metaname ("Minimum");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Minimum Minimum_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < Minimum > (parent, Minimum_Impl::metaname);
  }

  //
  // _create (const MetricsBase_in)
  //
  Minimum Minimum_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create_object < Minimum > (parent, Minimum_Impl::metaname);
  }

  //
  // accept
  //
  void Minimum_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Minimum (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

