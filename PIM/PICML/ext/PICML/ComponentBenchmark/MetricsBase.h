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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MetricsBase_Impl;
  typedef MetricsBase_Impl * MetricsBase_in;
  typedef ::GAME::Mga::Smart_Ptr < MetricsBase_Impl > MetricsBase;

  /**
   * @class MetricsBase_Impl
   *
   * Implementation for the MetricsBase model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    MetricsBase_Impl (void);

    // Initializing constructor.
    MetricsBase_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~MetricsBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of warmup
    void warmup (long val);

    /// Get the value of warmup
    long warmup (void) const;

    /// Set the value of iterations
    void iterations (long val);

    /// Get the value of iterations
    long iterations (void) const;

    /// Set the value of fileName
    void fileName (const std::string & val);

    /// Get the value of fileName
    std::string fileName (void) const;

    /// Set the value of priority
    void priority (long val);

    /// Get the value of priority
    long priority (void) const;

    /// Set the value of rate
    void rate (long val);

    /// Get the value of rate
    long rate (void) const;

    /// Set the value of resolution
    void resolution (const std::string & val);

    /// Get the value of resolution
    std::string resolution (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src WorkloadCharacteristics connection.
    size_t src_of_WorkloadCharacteristics (std::vector <WorkloadCharacteristics> & items) const;
    bool has_src_of_WorkloadCharacteristics (void) const;
    WorkloadCharacteristics src_of_WorkloadCharacteristics (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst MetricConnection connection.
    size_t dst_of_MetricConnection (std::vector <MetricConnection> & items) const;
    MetricConnection dst_of_MetricConnection (void) const;

    /// Get the dst BenchmarkCharacteristics connection.
    size_t dst_of_BenchmarkCharacteristics (std::vector <BenchmarkCharacteristics> & items) const;
    bool has_dst_of_BenchmarkCharacteristics (void) const;
    BenchmarkCharacteristics dst_of_BenchmarkCharacteristics (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Jitters (std::vector <Jitter> & items) const;
    ::GAME::Mga::Collection_T <Jitter> get_Jitters (void) const;

    size_t get_Maximums (std::vector <Maximum> & items) const;
    ::GAME::Mga::Collection_T <Maximum> get_Maximums (void) const;

    size_t get_Minimums (std::vector <Minimum> & items) const;
    ::GAME::Mga::Collection_T <Minimum> get_Minimums (void) const;

    size_t get_Averages (std::vector <Average> & items) const;
    ::GAME::Mga::Collection_T <Average> get_Averages (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MetricsBase.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_METRICSBASE
