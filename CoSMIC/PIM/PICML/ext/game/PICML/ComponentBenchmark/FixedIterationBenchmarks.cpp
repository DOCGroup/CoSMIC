// $Id$

#include "stdafx.h"
#include "FixedIterationBenchmarks.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string FixedIterationBenchmarks_Impl::metaname = "FixedIterationBenchmarks";

  //
  // FixedIterationBenchmarks_Impl
  //
  FixedIterationBenchmarks_Impl::FixedIterationBenchmarks_Impl (void)
  {
  }

  //
  // FixedIterationBenchmarks_Impl
  //
  FixedIterationBenchmarks_Impl::FixedIterationBenchmarks_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FixedIterationBenchmarks_Impl
  //
  FixedIterationBenchmarks_Impl::~FixedIterationBenchmarks_Impl (void)
  {
  }

  //
  // accept
  //
  void FixedIterationBenchmarks_Impl::accept (Visitor * v)
  {
    v->visit_FixedIterationBenchmarks (this);
  }

  //
  // benchmarkIterations
  //
  void FixedIterationBenchmarks_Impl::benchmarkIterations (long val)
  {
    static const std::string attr_benchmarkIterations ("benchmarkIterations");
    this->attribute (attr_benchmarkIterations)->int_value (val);
  }

  //
  // benchmarkIterations
  //
  long FixedIterationBenchmarks_Impl::benchmarkIterations (void) const
  {
    static const std::string attr_benchmarkIterations ("benchmarkIterations");
    return this->attribute (attr_benchmarkIterations)->int_value ();
  }
}

