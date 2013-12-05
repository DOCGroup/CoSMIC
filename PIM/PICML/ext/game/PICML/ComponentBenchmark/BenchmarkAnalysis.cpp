// $Id$

#include "StdAfx.h"
#include "BenchmarkAnalysis.h"

#if !defined (__GAME_INLINE__)
#include "BenchmarkAnalysis.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/OperationBase.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/LookupOperation.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/ComponentBenchmark/ComponentAnalyses.h"
#include "PICML/ComponentBenchmark/BenchmarkCharacteristics.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "PICML/ComponentBenchmark/PeriodicBenchmarks.h"
#include "PICML/ComponentBenchmark/FixedIterationBenchmarks.h"
#include "PICML/ComponentBenchmark/TriggerBenchmarks.h"
#include "PICML/ComponentBenchmark/WorkloadCharacteristics.h"
#include "PICML/ComponentBenchmark/TaskSet.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/EventRef.h"
#include "PICML/ComponentBenchmark/CompRef.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "PICML/ComponentBenchmark/Throughput.h"
#include "PICML/ComponentBenchmark/Latency.h"
#include "PICML/ComponentBenchmark/Task.h"
#include "PICML/ComponentBenchmark/WorkLoadOperationConnection.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "PICML/ComponentBenchmark/MetricConnection.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "PICML/ComponentBenchmark/Jitter.h"
#include "PICML/ComponentBenchmark/Maximum.h"
#include "PICML/ComponentBenchmark/Minimum.h"
#include "PICML/ComponentBenchmark/Average.h"
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
  // parent_ComponentAnalyses
  //
  ComponentAnalyses BenchmarkAnalysis_Impl::parent_ComponentAnalyses (void)
  {
    return ComponentAnalyses::_narrow (this->parent ());
  }

  //
  // get_OnewayOperations
  //
  size_t BenchmarkAnalysis_Impl::get_OnewayOperations (std::vector <OnewayOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_OnewayOperations
  //
  ::GAME::Mga::Iterator <OnewayOperation> BenchmarkAnalysis_Impl::get_OnewayOperations (void) const
  {
    return this->children <OnewayOperation> ();
  }

  //
  // get_TwowayOperations
  //
  size_t BenchmarkAnalysis_Impl::get_TwowayOperations (std::vector <TwowayOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_TwowayOperations
  //
  ::GAME::Mga::Iterator <TwowayOperation> BenchmarkAnalysis_Impl::get_TwowayOperations (void) const
  {
    return this->children <TwowayOperation> ();
  }

  //
  // get_LookupOperations
  //
  size_t BenchmarkAnalysis_Impl::get_LookupOperations (std::vector <LookupOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_LookupOperations
  //
  ::GAME::Mga::Iterator <LookupOperation> BenchmarkAnalysis_Impl::get_LookupOperations (void) const
  {
    return this->children <LookupOperation> ();
  }

  //
  // get_FactoryOperations
  //
  size_t BenchmarkAnalysis_Impl::get_FactoryOperations (std::vector <FactoryOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_FactoryOperations
  //
  ::GAME::Mga::Iterator <FactoryOperation> BenchmarkAnalysis_Impl::get_FactoryOperations (void) const
  {
    return this->children <FactoryOperation> ();
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

  //
  // get_PeriodicBenchmarkss
  //
  size_t BenchmarkAnalysis_Impl::get_PeriodicBenchmarkss (std::vector <PeriodicBenchmarks> & items) const
  {
    return this->children (items);
  }

  //
  // get_PeriodicBenchmarkss
  //
  ::GAME::Mga::Iterator <PeriodicBenchmarks> BenchmarkAnalysis_Impl::get_PeriodicBenchmarkss (void) const
  {
    return this->children <PeriodicBenchmarks> ();
  }

  //
  // get_FixedIterationBenchmarkss
  //
  size_t BenchmarkAnalysis_Impl::get_FixedIterationBenchmarkss (std::vector <FixedIterationBenchmarks> & items) const
  {
    return this->children (items);
  }

  //
  // get_FixedIterationBenchmarkss
  //
  ::GAME::Mga::Iterator <FixedIterationBenchmarks> BenchmarkAnalysis_Impl::get_FixedIterationBenchmarkss (void) const
  {
    return this->children <FixedIterationBenchmarks> ();
  }

  //
  // get_TriggerBenchmarkss
  //
  size_t BenchmarkAnalysis_Impl::get_TriggerBenchmarkss (std::vector <TriggerBenchmarks> & items) const
  {
    return this->children (items);
  }

  //
  // get_TriggerBenchmarkss
  //
  ::GAME::Mga::Iterator <TriggerBenchmarks> BenchmarkAnalysis_Impl::get_TriggerBenchmarkss (void) const
  {
    return this->children <TriggerBenchmarks> ();
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
  // get_Throughputs
  //
  size_t BenchmarkAnalysis_Impl::get_Throughputs (std::vector <Throughput> & items) const
  {
    return this->children (items);
  }

  //
  // get_Throughputs
  //
  ::GAME::Mga::Iterator <Throughput> BenchmarkAnalysis_Impl::get_Throughputs (void) const
  {
    return this->children <Throughput> ();
  }

  //
  // get_Latencys
  //
  size_t BenchmarkAnalysis_Impl::get_Latencys (std::vector <Latency> & items) const
  {
    return this->children (items);
  }

  //
  // get_Latencys
  //
  ::GAME::Mga::Iterator <Latency> BenchmarkAnalysis_Impl::get_Latencys (void) const
  {
    return this->children <Latency> ();
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
  // get_Jitters
  //
  size_t BenchmarkAnalysis_Impl::get_Jitters (std::vector <Jitter> & items) const
  {
    return this->children (items);
  }

  //
  // get_Jitters
  //
  ::GAME::Mga::Iterator <Jitter> BenchmarkAnalysis_Impl::get_Jitters (void) const
  {
    return this->children <Jitter> ();
  }

  //
  // get_Maximums
  //
  size_t BenchmarkAnalysis_Impl::get_Maximums (std::vector <Maximum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Maximums
  //
  ::GAME::Mga::Iterator <Maximum> BenchmarkAnalysis_Impl::get_Maximums (void) const
  {
    return this->children <Maximum> ();
  }

  //
  // get_Minimums
  //
  size_t BenchmarkAnalysis_Impl::get_Minimums (std::vector <Minimum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Minimums
  //
  ::GAME::Mga::Iterator <Minimum> BenchmarkAnalysis_Impl::get_Minimums (void) const
  {
    return this->children <Minimum> ();
  }

  //
  // get_Averages
  //
  size_t BenchmarkAnalysis_Impl::get_Averages (std::vector <Average> & items) const
  {
    return this->children (items);
  }

  //
  // get_Averages
  //
  ::GAME::Mga::Iterator <Average> BenchmarkAnalysis_Impl::get_Averages (void) const
  {
    return this->children <Average> ();
  }
}

