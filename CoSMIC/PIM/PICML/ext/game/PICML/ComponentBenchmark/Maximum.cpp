// $Id$

#include "StdAfx.h"
#include "Maximum.h"

#if !defined (__GAME_INLINE__)
#include "Maximum.inl"
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
  const std::string Maximum_Impl::metaname ("Maximum");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Maximum Maximum_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < Maximum > (parent, Maximum_Impl::metaname);
  }

  //
  // _create (const MetricsBase_in)
  //
  Maximum Maximum_Impl::_create (const MetricsBase_in parent)
  {
    return ::GAME::Mga::create_object < Maximum > (parent, Maximum_Impl::metaname);
  }

  //
  // accept
  //
  void Maximum_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Maximum (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

