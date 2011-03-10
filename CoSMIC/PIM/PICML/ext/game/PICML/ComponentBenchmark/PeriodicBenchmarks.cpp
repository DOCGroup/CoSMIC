// $Id$

#include "stdafx.h"
#include "PeriodicBenchmarks.h"

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
  const std::string PeriodicBenchmarks_Impl::metaname = "PeriodicBenchmarks";

  //
  // PeriodicBenchmarks_Impl
  //
  PeriodicBenchmarks_Impl::PeriodicBenchmarks_Impl (void)
  {
  }

  //
  // PeriodicBenchmarks_Impl
  //
  PeriodicBenchmarks_Impl::PeriodicBenchmarks_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PeriodicBenchmarks_Impl
  //
  PeriodicBenchmarks_Impl::~PeriodicBenchmarks_Impl (void)
  {
  }

  //
  // accept
  //
  void PeriodicBenchmarks_Impl::accept (Visitor * v)
  {
    v->visit_PeriodicBenchmarks (this);
  }

  //
  // timeperiod
  //
  void PeriodicBenchmarks_Impl::timeperiod (long val)
  {
    static const std::string attr_timeperiod ("timeperiod");
    this->attribute (attr_timeperiod)->int_value (val);
  }

  //
  // timeperiod
  //
  long PeriodicBenchmarks_Impl::timeperiod (void) const
  {
    static const std::string attr_timeperiod ("timeperiod");
    return this->attribute (attr_timeperiod)->int_value ();
  }
}

