// -*- C++ -*-

//============================================================================
/**
 * @file    WorkLoadOperationConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_WORKLOADOPERATIONCONNECTION_H_
#define _PICML_COMPONENTBENCHMARK_WORKLOADOPERATIONCONNECTION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkLoadOperationConnection_Impl;
  typedef WorkLoadOperationConnection_Impl * WorkLoadOperationConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkLoadOperationConnection_Impl> WorkLoadOperationConnection;

  // Forward decl.
  class Visitor;

  class PICML_Export WorkLoadOperationConnection_Impl :
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
    WorkLoadOperationConnection_Impl (void);

    /// Initializing constructor
    WorkLoadOperationConnection_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~WorkLoadOperationConnection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkLoadOperationConnection _create (const BenchmarkAnalysis_in parent);
    ///@}

    /// Get the src OperationRef connection point.
    OperationRef src_OperationRef (void);

    /// Get the dst Task connection point.
    Task dst_Task (void);

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
