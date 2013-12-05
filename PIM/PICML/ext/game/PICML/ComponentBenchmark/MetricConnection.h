// -*- C++ -*-

//============================================================================
/**
 * @file    MetricConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_METRICCONNECTION_H_
#define _PICML_COMPONENTBENCHMARK_METRICCONNECTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MetricConnection_Impl;
  typedef MetricConnection_Impl * MetricConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < MetricConnection_Impl > MetricConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class MetricConnection_Impl
   *
   * Implementation for the MetricConnection model element.
   */
  class PICML_Export MetricConnection_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static MetricConnection _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    MetricConnection_Impl (void);

    // Initializing constructor.
    MetricConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MetricConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
    OperationRef src_OperationRef (void) const;
    MetricsBase dst_MetricsBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MetricConnection.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_METRICCONNECTION
