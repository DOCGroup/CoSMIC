// -*- C++ -*-

//============================================================================
/**
 * @file    OperationRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_OPERATIONREF_H_
#define _PICML_COMPONENTBENCHMARK_OPERATIONREF_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OperationRef_Impl;
  typedef OperationRef_Impl * OperationRef_in;
  typedef ::GAME::Mga::Smart_Ptr <OperationRef_Impl> OperationRef;

  // Forward decl.
  class Visitor;

  class PICML_Export OperationRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    OperationRef_Impl (void);

    /// Initializing constructor
    OperationRef_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~OperationRef_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static OperationRef _create (const BenchmarkAnalysis_in parent);
    ///@}
    size_t in_WorkLoadOperationConnection_connections (std::vector <WorkLoadOperationConnection> & conns) const;
    size_t in_ComponentOperation_connections (std::vector <ComponentOperation> & conns) const;
    size_t in_MetricConnection_connections (std::vector <MetricConnection> & conns) const;
    size_t in_TimerConnection_connections (std::vector <TimerConnection> & conns) const;

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
