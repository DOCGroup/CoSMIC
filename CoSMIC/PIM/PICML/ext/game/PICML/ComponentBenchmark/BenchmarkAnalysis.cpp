// $Id$

#include "StdAfx.h"
#include "BenchmarkAnalysis.h"

#if !defined (__GAME_INLINE__)
#include "BenchmarkAnalysis.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/ComponentAnalyses.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/EventRef.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/TaskSet.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/CompRef.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string BenchmarkAnalysis_Impl::metaname ("BenchmarkAnalysis");

  //
  // _create (const ComponentAnalyses_in)
  //
  BenchmarkAnalysis BenchmarkAnalysis_Impl::_create (const ComponentAnalyses_in parent)
  {
    return ::GAME::Mga::create_root_object < BenchmarkAnalysis > (parent, BenchmarkAnalysis_Impl::metaname);
  }

  //
  // accept
  //
  void BenchmarkAnalysis_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_BenchmarkAnalysis (this);
    else
      v->visit_Model (this);
  }

  //
  // get_Events
  //
  size_t BenchmarkAnalysis_Impl::get_Events (std::vector <Event> & items) const
  {
    return this->children (items);
  }

  //
  // get_Events
  //
  ::GAME::Mga::Iterator <Event> BenchmarkAnalysis_Impl::get_Events (void) const
  {
    return this->children <Event> ();
  }

  //
  // get_OperationBases
  //
  size_t BenchmarkAnalysis_Impl::get_OperationBases (std::vector <OperationBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_OperationBases
  //
  ::GAME::Mga::Iterator <OperationBase> BenchmarkAnalysis_Impl::get_OperationBases (void) const
  {
    return this->children <OperationBase> ();
  }

  //
  // get_MetricConnections
  //
  size_t BenchmarkAnalysis_Impl::get_MetricConnections (std::vector <MetricConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_MetricConnections
  //
  ::GAME::Mga::Iterator <MetricConnection> BenchmarkAnalysis_Impl::get_MetricConnections (void) const
  {
    return this->children <MetricConnection> ();
  }

  //
  // get_DataAnalysisBases
  //
  size_t BenchmarkAnalysis_Impl::get_DataAnalysisBases (std::vector <DataAnalysisBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataAnalysisBases
  //
  ::GAME::Mga::Iterator <DataAnalysisBase> BenchmarkAnalysis_Impl::get_DataAnalysisBases (void) const
  {
    return this->children <DataAnalysisBase> ();
  }

  //
  // get_TimeProbes
  //
  size_t BenchmarkAnalysis_Impl::get_TimeProbes (std::vector <TimeProbe> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimeProbes
  //
  ::GAME::Mga::Iterator <TimeProbe> BenchmarkAnalysis_Impl::get_TimeProbes (void) const
  {
    return this->children <TimeProbe> ();
  }

  //
  // get_TimerConnections
  //
  size_t BenchmarkAnalysis_Impl::get_TimerConnections (std::vector <TimerConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimerConnections
  //
  ::GAME::Mga::Iterator <TimerConnection> BenchmarkAnalysis_Impl::get_TimerConnections (void) const
  {
    return this->children <TimerConnection> ();
  }

  //
  // get_MetricsBases
  //
  size_t BenchmarkAnalysis_Impl::get_MetricsBases (std::vector <MetricsBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_MetricsBases
  //
  ::GAME::Mga::Iterator <MetricsBase> BenchmarkAnalysis_Impl::get_MetricsBases (void) const
  {
    return this->children <MetricsBase> ();
  }

  //
  // get_OperationRefs
  //
  size_t BenchmarkAnalysis_Impl::get_OperationRefs (std::vector <OperationRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_OperationRefs
  //
  ::GAME::Mga::Iterator <OperationRef> BenchmarkAnalysis_Impl::get_OperationRefs (void) const
  {
    return this->children <OperationRef> ();
  }

  //
  // get_EventRefs
  //
  size_t BenchmarkAnalysis_Impl::get_EventRefs (std::vector <EventRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_EventRefs
  //
  ::GAME::Mga::Iterator <EventRef> BenchmarkAnalysis_Impl::get_EventRefs (void) const
  {
    return this->children <EventRef> ();
  }

  //
  // get_TimerEventSinkConns
  //
  size_t BenchmarkAnalysis_Impl::get_TimerEventSinkConns (std::vector <TimerEventSinkConn> & items) const
  {
    return this->children (items);
  }

  //
  // get_TimerEventSinkConns
  //
  ::GAME::Mga::Iterator <TimerEventSinkConn> BenchmarkAnalysis_Impl::get_TimerEventSinkConns (void) const
  {
    return this->children <TimerEventSinkConn> ();
  }

  //
  // get_TaskSets
  //
  size_t BenchmarkAnalysis_Impl::get_TaskSets (std::vector <TaskSet> & items) const
  {
    return this->children (items);
  }

  //
  // get_TaskSets
  //
  ::GAME::Mga::Iterator <TaskSet> BenchmarkAnalysis_Impl::get_TaskSets (void) const
  {
    return this->children <TaskSet> ();
  }

  //
  // get_Tasks
  //
  size_t BenchmarkAnalysis_Impl::get_Tasks (std::vector <Task> & items) const
  {
    return this->children (items);
  }

  //
  // get_Tasks
  //
  ::GAME::Mga::Iterator <Task> BenchmarkAnalysis_Impl::get_Tasks (void) const
  {
    return this->children <Task> ();
  }

  //
  // get_WorkloadCharacteristicss
  //
  size_t BenchmarkAnalysis_Impl::get_WorkloadCharacteristicss (std::vector <WorkloadCharacteristics> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkloadCharacteristicss
  //
  ::GAME::Mga::Iterator <WorkloadCharacteristics> BenchmarkAnalysis_Impl::get_WorkloadCharacteristicss (void) const
  {
    return this->children <WorkloadCharacteristics> ();
  }

  //
  // get_ComponentOperations
  //
  size_t BenchmarkAnalysis_Impl::get_ComponentOperations (std::vector <ComponentOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentOperations
  //
  ::GAME::Mga::Iterator <ComponentOperation> BenchmarkAnalysis_Impl::get_ComponentOperations (void) const
  {
    return this->children <ComponentOperation> ();
  }

  //
  // get_CompRefs
  //
  size_t BenchmarkAnalysis_Impl::get_CompRefs (std::vector <CompRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_CompRefs
  //
  ::GAME::Mga::Iterator <CompRef> BenchmarkAnalysis_Impl::get_CompRefs (void) const
  {
    return this->children <CompRef> ();
  }

  //
  // get_WorkLoadOperationConnections
  //
  size_t BenchmarkAnalysis_Impl::get_WorkLoadOperationConnections (std::vector <WorkLoadOperationConnection> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkLoadOperationConnections
  //
  ::GAME::Mga::Iterator <WorkLoadOperationConnection> BenchmarkAnalysis_Impl::get_WorkLoadOperationConnections (void) const
  {
    return this->children <WorkLoadOperationConnection> ();
  }

  //
  // get_BenchmarkTypes
  //
  size_t BenchmarkAnalysis_Impl::get_BenchmarkTypes (std::vector <BenchmarkType> & items) const
  {
    return this->children (items);
  }

  //
  // get_BenchmarkTypes
  //
  ::GAME::Mga::Iterator <BenchmarkType> BenchmarkAnalysis_Impl::get_BenchmarkTypes (void) const
  {
    return this->children <BenchmarkType> ();
  }

  //
  // get_BenchmarkCharacteristicss
  //
  size_t BenchmarkAnalysis_Impl::get_BenchmarkCharacteristicss (std::vector <BenchmarkCharacteristics> & items) const
  {
    return this->children (items);
  }

  //
  // get_BenchmarkCharacteristicss
  //
  ::GAME::Mga::Iterator <BenchmarkCharacteristics> BenchmarkAnalysis_Impl::get_BenchmarkCharacteristicss (void) const
  {
    return this->children <BenchmarkCharacteristics> ();
  }
}

