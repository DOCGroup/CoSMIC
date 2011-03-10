// $Id$

#include "stdafx.h"
#include "BenchmarkAnalysis.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/CompRef.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "PICML/ComponentBenchmark/TaskSet.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/EventRef.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/ComponentBenchmark/ComponentAnalyses.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkAnalysis_Impl::metaname = "BenchmarkAnalysis";

  //
  // BenchmarkAnalysis_Impl
  //
  BenchmarkAnalysis_Impl::BenchmarkAnalysis_Impl (void)
  {
  }

  //
  // BenchmarkAnalysis_Impl
  //
  BenchmarkAnalysis_Impl::BenchmarkAnalysis_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BenchmarkAnalysis_Impl
  //
  BenchmarkAnalysis_Impl::~BenchmarkAnalysis_Impl (void)
  {
  }

  //
  // accept
  //
  void BenchmarkAnalysis_Impl::accept (Visitor * v)
  {
    v->visit_BenchmarkAnalysis (this);
  }

  //
  // _create
  //
  BenchmarkAnalysis BenchmarkAnalysis_Impl::_create (const ComponentAnalyses_in parent)
  {
    return ::GAME::Mga::create_root_object <BenchmarkAnalysis> (parent, BenchmarkAnalysis_Impl::metaname);
  }

  //
  // get_BenchmarkCharacteristicss
  //
  size_t BenchmarkAnalysis_Impl::get_BenchmarkCharacteristicss (std::vector <BenchmarkCharacteristics> & items) const
  {
    return this->children (items);
  }

  //
  // get_BenchmarkTypes
  //
  size_t BenchmarkAnalysis_Impl::get_BenchmarkTypes (std::vector <BenchmarkType> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkLoadOperationConnections
  //
  size_t BenchmarkAnalysis_Impl::get_WorkLoadOperationConnections (std::vector <WorkLoadOperationConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_CompRefs
  //
  size_t BenchmarkAnalysis_Impl::get_CompRefs (std::vector <CompRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentOperations
  //
  size_t BenchmarkAnalysis_Impl::get_ComponentOperations (std::vector <ComponentOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkloadCharacteristicss
  //
  size_t BenchmarkAnalysis_Impl::get_WorkloadCharacteristicss (std::vector <WorkloadCharacteristics> & items) const
  {
    return this->children (items);
  }

  //
  // get_Tasks
  //
  size_t BenchmarkAnalysis_Impl::get_Tasks (std::vector <Task> & items) const
  {
    return this->children (items);
  }

  //
  // get_TaskSets
  //
  size_t BenchmarkAnalysis_Impl::get_TaskSets (std::vector <TaskSet> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimerEventSinkConns
  //
  size_t BenchmarkAnalysis_Impl::get_TimerEventSinkConns (std::vector <TimerEventSinkConn> & items) const
  {
    return this->children (items);
  }

  //
  // get_EventRefs
  //
  size_t BenchmarkAnalysis_Impl::get_EventRefs (std::vector <EventRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_OperationRefs
  //
  size_t BenchmarkAnalysis_Impl::get_OperationRefs (std::vector <OperationRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_MetricsBases
  //
  size_t BenchmarkAnalysis_Impl::get_MetricsBases (std::vector <MetricsBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_Events
  //
  size_t BenchmarkAnalysis_Impl::get_Events (std::vector <Event> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimeProbes
  //
  size_t BenchmarkAnalysis_Impl::get_TimeProbes (std::vector <TimeProbe> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataAnalysisBases
  //
  size_t BenchmarkAnalysis_Impl::get_DataAnalysisBases (std::vector <DataAnalysisBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_MetricConnections
  //
  size_t BenchmarkAnalysis_Impl::get_MetricConnections (std::vector <MetricConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimerConnections
  //
  size_t BenchmarkAnalysis_Impl::get_TimerConnections (std::vector <TimerConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_OperationBases
  //
  size_t BenchmarkAnalysis_Impl::get_OperationBases (std::vector <OperationBase> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ComponentAnalyses
  //
  ComponentAnalyses BenchmarkAnalysis_Impl::parent_ComponentAnalyses (void) const
  {
    return ::GAME::Mga::get_parent <ComponentAnalyses> (this->object_.p);
  }
}

