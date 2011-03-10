// -*- C++ -*-

//============================================================================
/**
 * @file    WorkloadCharacteristics.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_WORKLOADCHARACTERISTICS_H_
#define _PICML_COMPONENTBENCHMARK_WORKLOADCHARACTERISTICS_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkloadCharacteristics_Impl;
  typedef WorkloadCharacteristics_Impl * WorkloadCharacteristics_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkloadCharacteristics_Impl> WorkloadCharacteristics;

  // Forward decl.
  class Visitor;

  class PICML_Export WorkloadCharacteristics_Impl :
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
    WorkloadCharacteristics_Impl (void);

    /// Initializing constructor
    WorkloadCharacteristics_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~WorkloadCharacteristics_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkloadCharacteristics _create (const BenchmarkAnalysis_in parent);
    ///@}

    /// Get the src MetricsBase connection point.
    MetricsBase src_MetricsBase (void);

    /// Get the dst TaskSet connection point.
    TaskSet dst_TaskSet (void);

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
