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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BenchmarkAnalysis_Impl;
  typedef BenchmarkAnalysis_Impl * BenchmarkAnalysis_in;
  typedef ::GAME::Mga::Smart_Ptr <BenchmarkAnalysis_Impl> BenchmarkAnalysis;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    BenchmarkAnalysis_Impl (void);

    /// Initializing constructor
    BenchmarkAnalysis_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~BenchmarkAnalysis_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static BenchmarkAnalysis _create (const ComponentAnalyses_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_BenchmarkCharacteristicss (std::vector <BenchmarkCharacteristics> & items) const;
    size_t get_BenchmarkTypes (std::vector <BenchmarkType> & items) const;
    size_t get_WorkLoadOperationConnections (std::vector <WorkLoadOperationConnection> & items) const;
    size_t get_CompRefs (std::vector <CompRef> & items) const;
    size_t get_ComponentOperations (std::vector <ComponentOperation> & items) const;
    size_t get_WorkloadCharacteristicss (std::vector <WorkloadCharacteristics> & items) const;
    size_t get_Tasks (std::vector <Task> & items) const;
    size_t get_TaskSets (std::vector <TaskSet> & items) const;
    size_t get_TimerEventSinkConns (std::vector <TimerEventSinkConn> & items) const;
    size_t get_EventRefs (std::vector <EventRef> & items) const;
    size_t get_OperationRefs (std::vector <OperationRef> & items) const;
    size_t get_MetricsBases (std::vector <MetricsBase> & items) const;
    size_t get_Events (std::vector <Event> & items) const;
    size_t get_TimeProbes (std::vector <TimeProbe> & items) const;
    size_t get_DataAnalysisBases (std::vector <DataAnalysisBase> & items) const;
    size_t get_MetricConnections (std::vector <MetricConnection> & items) const;
    size_t get_TimerConnections (std::vector <TimerConnection> & items) const;
    size_t get_OperationBases (std::vector <OperationBase> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAnalyses parent_ComponentAnalyses (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
