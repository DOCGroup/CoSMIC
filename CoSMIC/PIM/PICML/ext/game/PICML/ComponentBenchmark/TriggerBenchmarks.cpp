// $Id$

#include "stdafx.h"
#include "TriggerBenchmarks.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TriggerBenchmarks_Impl::metaname = "TriggerBenchmarks";

  //
  // TriggerBenchmarks_Impl
  //
  TriggerBenchmarks_Impl::TriggerBenchmarks_Impl (void)
  {
  }

  //
  // TriggerBenchmarks_Impl
  //
  TriggerBenchmarks_Impl::TriggerBenchmarks_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TriggerBenchmarks_Impl
  //
  TriggerBenchmarks_Impl::~TriggerBenchmarks_Impl (void)
  {
  }

  //
  // accept
  //
  void TriggerBenchmarks_Impl::accept (Visitor * v)
  {
    v->visit_TriggerBenchmarks (this);
  }
}

