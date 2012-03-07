// $Id$

#include "StdAfx.h"
#include "WorkloadCharacteristics.h"

#if !defined (__GAME_INLINE__)
#include "WorkloadCharacteristics.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/TaskSet.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkloadCharacteristics_Impl::metaname ("WorkloadCharacteristics");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  WorkloadCharacteristics WorkloadCharacteristics_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < WorkloadCharacteristics > (parent, WorkloadCharacteristics_Impl::metaname);
  }

  //
  // accept
  //
  void WorkloadCharacteristics_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_WorkloadCharacteristics (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // MetricsBase
  //
  MetricsBase WorkloadCharacteristics_Impl::src_MetricsBase (void) const
  {
    return MetricsBase::_narrow (this->src ());
  }

  //
  // TaskSet
  //
  TaskSet WorkloadCharacteristics_Impl::dst_TaskSet (void) const
  {
    return TaskSet::_narrow (this->dst ());
  }
}

