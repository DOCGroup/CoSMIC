// -*- C++ -*-

//============================================================================
/**
 * @file    MetricsBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_METRICSBASE_H_
#define _PICML_COMPONENTBENCHMARK_METRICSBASE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MetricsBase_Impl;
  typedef MetricsBase_Impl * MetricsBase_in;
  typedef ::GAME::Mga::Smart_Ptr <MetricsBase_Impl> MetricsBase;

  class PICML_Export MetricsBase_Impl :
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
    MetricsBase_Impl (void);

    /// Initializing constructor
    MetricsBase_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~MetricsBase_Impl (void) = 0;

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of resolution
    void resolution (const std::string & val);

    /// Get the value of resolution
    std::string resolution (void) const;

    /// Set the value of rate
    void rate (long val);

    /// Get the value of rate
    long rate (void) const;

    /// Set the value of priority
    void priority (long val);

    /// Get the value of priority
    long priority (void) const;

    /// Set the value of iterations
    void iterations (long val);

    /// Get the value of iterations
    long iterations (void) const;

    /// Set the value of warmup
    void warmup (long val);

    /// Get the value of warmup
    long warmup (void) const;

    /// Set the value of fileName
    void fileName (const std::string & val);

    /// Get the value of fileName
    std::string fileName (void) const;
    ///@}
    size_t in_WorkloadCharacteristics_connections (std::vector <WorkloadCharacteristics> & conns) const;
    size_t in_BenchmarkCharacteristics_connections (std::vector <BenchmarkCharacteristics> & conns) const;
    size_t in_MetricConnection_connections (std::vector <MetricConnection> & conns) const;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_DataAnalysisBases (std::vector <DataAnalysisBase> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
