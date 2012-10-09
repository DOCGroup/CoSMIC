// -*- C++ -*-

//============================================================================
/**
 * @file    BenchmarkAnalysis.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_BENCHMARKANALYSIS_H_
#define _PICML_COMPONENTBENCHMARK_BENCHMARKANALYSIS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BenchmarkAnalysis_Impl;
  typedef BenchmarkAnalysis_Impl * BenchmarkAnalysis_in;
  typedef ::GAME::Mga::Smart_Ptr < BenchmarkAnalysis_Impl > BenchmarkAnalysis;

  // Forward decl.
  class Visitor;

  /**
   * @class BenchmarkAnalysis_Impl
   *
   * Implementation for the BenchmarkAnalysis model element.
   */
  class PICML_Export BenchmarkAnalysis_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static BenchmarkAnalysis _create (const ComponentAnalyses_in parent);
    ///@}

    // Default constructor.
    BenchmarkAnalysis_Impl (void);

    // Initializing constructor.
    BenchmarkAnalysis_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~BenchmarkAnalysis_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAnalyses parent_ComponentAnalyses (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_OnewayOperations (std::vector <OnewayOperation> & items) const;
    ::GAME::Mga::Iterator <OnewayOperation> get_OnewayOperations (void) const;

    size_t get_TwowayOperations (std::vector <TwowayOperation> & items) const;
    ::GAME::Mga::Iterator <TwowayOperation> get_TwowayOperations (void) const;

    size_t get_LookupOperations (std::vector <LookupOperation> & items) const;
    ::GAME::Mga::Iterator <LookupOperation> get_LookupOperations (void) const;

    size_t get_FactoryOperations (std::vector <FactoryOperation> & items) const;
    ::GAME::Mga::Iterator <FactoryOperation> get_FactoryOperations (void) const;

    size_t get_BenchmarkCharacteristicss (std::vector <BenchmarkCharacteristics> & items) const;
    ::GAME::Mga::Iterator <BenchmarkCharacteristics> get_BenchmarkCharacteristicss (void) const;

    size_t get_PeriodicBenchmarkss (std::vector <PeriodicBenchmarks> & items) const;
    ::GAME::Mga::Iterator <PeriodicBenchmarks> get_PeriodicBenchmarkss (void) const;

    size_t get_FixedIterationBenchmarkss (std::vector <FixedIterationBenchmarks> & items) const;
    ::GAME::Mga::Iterator <FixedIterationBenchmarks> get_FixedIterationBenchmarkss (void) const;

    size_t get_TriggerBenchmarkss (std::vector <TriggerBenchmarks> & items) const;
    ::GAME::Mga::Iterator <TriggerBenchmarks> get_TriggerBenchmarkss (void) const;

    size_t get_WorkloadCharacteristicss (std::vector <WorkloadCharacteristics> & items) const;
    ::GAME::Mga::Iterator <WorkloadCharacteristics> get_WorkloadCharacteristicss (void) const;

    size_t get_TaskSets (std::vector <TaskSet> & items) const;
    ::GAME::Mga::Iterator <TaskSet> get_TaskSets (void) const;

    size_t get_OperationRefs (std::vector <OperationRef> & items) const;
    ::GAME::Mga::Iterator <OperationRef> get_OperationRefs (void) const;

    size_t get_EventRefs (std::vector <EventRef> & items) const;
    ::GAME::Mga::Iterator <EventRef> get_EventRefs (void) const;

    size_t get_CompRefs (std::vector <CompRef> & items) const;
    ::GAME::Mga::Iterator <CompRef> get_CompRefs (void) const;

    size_t get_Events (std::vector <Event> & items) const;
    ::GAME::Mga::Iterator <Event> get_Events (void) const;

    size_t get_Throughputs (std::vector <Throughput> & items) const;
    ::GAME::Mga::Iterator <Throughput> get_Throughputs (void) const;

    size_t get_Latencys (std::vector <Latency> & items) const;
    ::GAME::Mga::Iterator <Latency> get_Latencys (void) const;

    size_t get_Tasks (std::vector <Task> & items) const;
    ::GAME::Mga::Iterator <Task> get_Tasks (void) const;

    size_t get_WorkLoadOperationConnections (std::vector <WorkLoadOperationConnection> & items) const;
    ::GAME::Mga::Iterator <WorkLoadOperationConnection> get_WorkLoadOperationConnections (void) const;

    size_t get_TimerConnections (std::vector <TimerConnection> & items) const;
    ::GAME::Mga::Iterator <TimerConnection> get_TimerConnections (void) const;

    size_t get_TimeProbes (std::vector <TimeProbe> & items) const;
    ::GAME::Mga::Iterator <TimeProbe> get_TimeProbes (void) const;

    size_t get_TimerEventSinkConns (std::vector <TimerEventSinkConn> & items) const;
    ::GAME::Mga::Iterator <TimerEventSinkConn> get_TimerEventSinkConns (void) const;

    size_t get_ComponentOperations (std::vector <ComponentOperation> & items) const;
    ::GAME::Mga::Iterator <ComponentOperation> get_ComponentOperations (void) const;

    size_t get_MetricConnections (std::vector <MetricConnection> & items) const;
    ::GAME::Mga::Iterator <MetricConnection> get_MetricConnections (void) const;

    size_t get_Jitters (std::vector <Jitter> & items) const;
    ::GAME::Mga::Iterator <Jitter> get_Jitters (void) const;

    size_t get_Maximums (std::vector <Maximum> & items) const;
    ::GAME::Mga::Iterator <Maximum> get_Maximums (void) const;

    size_t get_Minimums (std::vector <Minimum> & items) const;
    ::GAME::Mga::Iterator <Minimum> get_Minimums (void) const;

    size_t get_Averages (std::vector <Average> & items) const;
    ::GAME::Mga::Iterator <Average> get_Averages (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "BenchmarkAnalysis.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_BENCHMARKANALYSIS
