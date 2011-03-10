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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MetricConnection_Impl;
  typedef MetricConnection_Impl * MetricConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <MetricConnection_Impl> MetricConnection;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    MetricConnection_Impl (void);

    /// Initializing constructor
    MetricConnection_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~MetricConnection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static MetricConnection _create (const BenchmarkAnalysis_in parent);
    ///@}

    /// Get the src OperationRef connection point.
    OperationRef src_OperationRef (void);

    /// Get the dst MetricsBase connection point.
    MetricsBase dst_MetricsBase (void);

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
